#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int dx[] = {0, 0, 1, -1, 0};
const int dy[] = {1, -1, 0, 0, 0};

int N, M, T, U;
int V[10][10];
int sx[8], sy[8];
int tx[8], ty[8];
int ex[8], ey[8];
int O[10][10];
int L[10][10];

bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> M >> T >> U)) return 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> V[i][j];
    }
    for (int i = 0; i < M; ++i) {
        cin >> sx[i] >> sy[i];
        ex[i] = sx[i];
        ey[i] = sy[i];
    }

    // 初期状態のセットアップ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            O[i][j] = -1;
            L[i][j] = 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        O[sx[i]][sy[i]] = i;
        L[sx[i]][sy[i]] = 1;
    }

    for (int t = 0; t < T; ++t) {
        // プレイヤー0の到達可能領土と移動候補の計算
        vector<vector<bool>> reach(N, vector<bool>(N, false));
        queue<pair<int, int>> q;
        q.push({ex[0], ey[0]});
        reach[ex[0]][ey[0]] = true;
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i], nc = c + dy[i];
                if (is_valid(nr, nc) && !reach[nr][nc] && O[nr][nc] == 0) {
                    reach[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        vector<pair<int, int>> candidates;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                bool can = reach[r][c];
                if (!can) {
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dx[i], nc = c + dy[i];
                        if (is_valid(nr, nc) && reach[nr][nc]) { can = true; break; }
                    }
                }
                if (can) {
                    bool blocked = false;
                    for (int p = 1; p < M; ++p) {
                        if (ex[p] == r && ey[p] == c) { blocked = true; break; }
                    }
                    if (!blocked) candidates.push_back({r, c});
                }
            }
        }

        // 現在のスコア計算
        vector<long long> S(M, 0);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (O[r][c] != -1) S[O[r][c]] += (long long)V[r][c] * L[r][c];
            }
        }

        long long SA = 0;
        int leader = -1;
        for (int p = 1; p < M; ++p) {
            if (S[p] > SA) { SA = S[p]; leader = p; }
        }
        if (SA == 0) SA = 1;

        // AIの移動確率推定 (衝突回避のため)
        vector<vector<double>> prob_collision(N, vector<double>(N, 0.0));
        for (int p = 1; p < M; ++p) {
            vector<vector<bool>> areach(N, vector<bool>(N, false));
            queue<pair<int, int>> aq; aq.push({ex[p], ey[p]}); areach[ex[p]][ey[p]] = true;
            while(!aq.empty()){
                auto [r, c] = aq.front(); aq.pop();
                for(int i=0; i<4; ++i){
                    int nr=r+dx[i], nc=c+dy[i];
                    if(is_valid(nr,nc) && !areach[nr][nc] && O[nr][nc]==p){
                        areach[nr][nc]=true; aq.push({nr,nc});
                    }
                }
            }
            vector<pair<int, int>> b_p;
            for(int r=0; r<N; ++r) for(int c=0; c<N; ++c){
                bool can = areach[r][c];
                if(!can) for(int i=0; i<4; ++i){
                    int nr=r+dx[i], nc=c+dy[i];
                    if(is_valid(nr,nc) && areach[nr][nc]){ can=true; break; }
                }
                if(can){
                    bool blocked = false;
                    for(int other=0; other<M; ++other) if(p!=other && ex[other]==r && ey[other]==c){ blocked=true; break; }
                    if(!blocked) b_p.push_back({r, c});
                }
            }
            
            double max_val = -1.0;
            vector<pair<int, int>> bests;
            for(auto& pos : b_p){
                int r=pos.first, c=pos.second;
                double val = 0;
                if(O[r][c] == -1) val = V[r][c] * 0.65;
                else if(O[r][c] == p) val = (L[r][c] < U) ? V[r][c] * 0.65 : 0;
                else val = V[r][c] * 0.65;
                
                if(val > max_val) { max_val = val; bests = {{r, c}}; }
                else if(val == max_val) bests.push_back({r, c});
            }
            double eps = 0.3;
            for(auto& pos : b_p){
                double p_m = eps / (double)b_p.size();
                for(auto& b : bests) if(b.first == pos.first && b.second == pos.second) p_m += (1.0 - eps) / (double)bests.size();
                prob_collision[pos.first][pos.second] += p_m;
            }
        }

        // 最善の移動先を選択
        pair<int, int> best_move = {ex[0], ey[0]};
        double max_eval = -1e18;

        for (auto& cand : candidates) {
            int r = cand.first, c = cand.second;
            long long dS0 = 0, dSA = 0;
            double exp_bonus_val = 0;

            if (O[r][c] == -1) {
                dS0 = V[r][c];
                // 序盤ほど拡張ボーナスを大きくする
                exp_bonus_val = V[r][c] * 0.8 * (double)(T - t) / T;
            } else if (O[r][c] == 0) {
                if (L[r][c] < U) dS0 = V[r][c];
            } else {
                if (L[r][c] == 1) {
                    dS0 = V[r][c];
                    if (O[r][c] == leader) dSA = -V[r][c];
                    else if (S[O[r][c]] > SA * 0.9) dSA = -V[r][c] * 0.7;
                    else if (S[O[r][c]] > SA * 0.7) dSA = -V[r][c] * 0.3;
                } else {
                    if (O[r][c] == leader) dSA = -V[r][c];
                    else if (S[O[r][c]] > SA * 0.9) dSA = -V[r][c] * 0.7;
                }
            }

            // 次のターンでのスコア比率の期待値を計算
            double next_S0 = (double)S[0] + dS0;
            double next_SA = (double)SA + dSA;
            if (next_SA <= 0) next_SA = 1.0;

            double ratio_gain = (next_S0 / next_SA) - ((double)S[0] / SA);
            double bonus = exp_bonus_val / next_SA;
            
            double p_c = min(0.9, prob_collision[r][c]);
            double eval = (ratio_gain + bonus) * (1.0 - p_c);

            if (eval > max_eval) {
                max_eval = eval;
                best_move = {r, c};
            }
        }

        // 移動先の出力
        cout << best_move.first << " " << best_move.second << endl;

        // ターン終了情報の更新
        for (int i = 0; i < M; ++i) cin >> tx[i] >> ty[i];
        for (int i = 0; i < M; ++i) cin >> ex[i] >> ey[i];
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> O[i][j];
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> L[i][j];
    }

    return 0;
}
