#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>

using namespace std;

// 定数定義
const int N = 20;
const int M = 50;
const int K = 10;

// 構造体定義
struct Door {
    int d;  // 0: 上下 (i,j)-(i+1,j), 1: 左右 (i,j)-(i,j+1)
    int i, j;
    int g;  // 扉の型 (2k+1 のみを使用)
};

struct Switch {
    int i, j;
    int s;  // スイッチの種類 (0 ~ K-1)
};

struct Edge {
    int d;
    int i, j;
};

// グローバル変数
string C[N];
int door_h[N][N];
int door_v[N][N];
int switch_map[N][N];

// BFS高速化用
int vis[1024][N][N];
int dist_bfs[1024][N][N];
int iter_count = 0;

struct State {
    int mask;
    int i, j;
};
State que[500000];

// 勇者の最小行動回数 T を計算する BFS
int calc_T() {
    iter_count++;
    vis[0][0][0] = iter_count;
    dist_bfs[0][0][0] = 0;

    int head = 0, tail = 0;
    que[tail++] = {0, 0, 0};

    while (head < tail) {
        State curr = que[head++];
        int mask = curr.mask;
        int i = curr.i;
        int j = curr.j;
        int d = dist_bfs[mask][i][j];

        if (i == N - 1 && j == N - 1) {
            return d;
        }

        // Up
        if (i > 0 && C[i - 1][j] == '.') {
            int g = door_h[i - 1][j];
            if (g == -1 || (((mask >> (g / 2)) & 1) == (g & 1))) {
                if (vis[mask][i - 1][j] != iter_count) {
                    vis[mask][i - 1][j] = iter_count;
                    dist_bfs[mask][i - 1][j] = d + 1;
                    que[tail++] = {mask, i - 1, j};
                }
            }
        }
        // Down
        if (i < N - 1 && C[i + 1][j] == '.') {
            int g = door_h[i][j];
            if (g == -1 || (((mask >> (g / 2)) & 1) == (g & 1))) {
                if (vis[mask][i + 1][j] != iter_count) {
                    vis[mask][i + 1][j] = iter_count;
                    dist_bfs[mask][i + 1][j] = d + 1;
                    que[tail++] = {mask, i + 1, j};
                }
            }
        }
        // Left
        if (j > 0 && C[i][j - 1] == '.') {
            int g = door_v[i][j - 1];
            if (g == -1 || (((mask >> (g / 2)) & 1) == (g & 1))) {
                if (vis[mask][i][j - 1] != iter_count) {
                    vis[mask][i][j - 1] = iter_count;
                    dist_bfs[mask][i][j - 1] = d + 1;
                    que[tail++] = {mask, i, j - 1};
                }
            }
        }
        // Right
        if (j < N - 1 && C[i][j + 1] == '.') {
            int g = door_v[i][j];
            if (g == -1 || (((mask >> (g / 2)) & 1) == (g & 1))) {
                if (vis[mask][i][j + 1] != iter_count) {
                    vis[mask][i][j + 1] = iter_count;
                    dist_bfs[mask][i][j + 1] = d + 1;
                    que[tail++] = {mask, i, j + 1};
                }
            }
        }

        // スイッチを押す
        int s = switch_map[i][j];
        if (s != -1) {
            int nmask = mask ^ (1 << s);
            if (vis[nmask][i][j] != iter_count) {
                vis[nmask][i][j] = iter_count;
                dist_bfs[nmask][i][j] = d + 1;
                que[tail++] = {nmask, i, j};
            }
        }
    }
    return 0;
}

// 何もない状態でのスタート(0,0)から玉座(N-1,N-1)への最短経路を復元する
vector<Edge> get_initial_shortest_path() {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        int i = curr.first, j = curr.second;
        if (i == N - 1 && j == N - 1) break;
        
        for (int d = 0; d < 4; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && C[ni][nj] == '.' && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1;
                parent[ni][nj] = {i, j};
                q.push({ni, nj});
            }
        }
    }
    
    vector<Edge> path_edges;
    if (dist[N - 1][N - 1] == -1) return path_edges;
    
    int curr_i = N - 1, curr_j = N - 1;
    while (curr_i != 0 || curr_j != 0) {
        auto p = parent[curr_i][curr_j];
        int p_i = p.first, p_j = p.second;
        if (p_i == curr_i) {
            path_edges.push_back({1, curr_i, min(p_j, curr_j)});
        } else {
            path_edges.push_back({0, min(p_i, curr_i), curr_j});
        }
        curr_i = p_i;
        curr_j = p_j;
    }
    return path_edges;
}

mt19937 rng(42);

bool accept(int next_T, int current_T, double temp) {
    if (next_T >= current_T) return true;
    double p = exp((next_T - current_T) / temp);
    return (rng() % 10000 / 10000.0) < p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dummy_N, dummy_M, dummy_K;
    if (!(cin >> dummy_N >> dummy_M >> dummy_K)) return 0;

    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    // マップの初期化
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            door_h[i][j] = -1;
            door_v[i][j] = -1;
            switch_map[i][j] = -1;
        }
    }

    // 1. 初期状態での最短経路（玉座への道）を特定
    vector<Edge> path_edges = get_initial_shortest_path();

    // 2. 玉座に近い側のエッジに K 種類のドア (2k+1) を強制配置して固定する
    int num_fixed = min(K, (int)path_edges.size());
    bool is_fixed_h[N][N] = {};
    bool is_fixed_v[N][N] = {};
    
    vector<Door> doors;
    for (int k = 0; k < num_fixed; ++k) {
        Edge e = path_edges[k];
        int g = 2 * k + 1; // ドアの種類 (1, 3, 5, ..., 2K-1) のみ
        if (e.d == 0) {
            door_h[e.i][e.j] = g;
            is_fixed_h[e.i][e.j] = true;
        } else {
            door_v[e.i][e.j] = g;
            is_fixed_v[e.i][e.j] = true;
        }
        doors.push_back({e.d, e.i, e.j, g});
    }

    // 設置可能な自由エッジと空きマスのリストアップ
    vector<Edge> all_edges;
    vector<pair<int, int>> all_empty_cells;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (C[i][j] == '.') {
                all_empty_cells.push_back({i, j});
                if (i + 1 < N && C[i + 1][j] == '.') {
                    if (!is_fixed_h[i][j]) all_edges.push_back({0, i, j});
                }
                if (j + 1 < N && C[i][j + 1] == '.') {
                    if (!is_fixed_v[i][j]) all_edges.push_back({1, i, j});
                }
            }
        }
    }

    // 3. 固定した2k+1型ドアに対応するK種類のスイッチをランダムに初期配置
    vector<Switch> switches;
    for (int k = 0; k < num_fixed; ++k) {
        int s = k; // ドア 2k+1 に対応するスイッチは k
        if (all_empty_cells.empty()) break;
        int attempts = 0;
        while (attempts < 1000) {
            int idx = rng() % all_empty_cells.size();
            auto cell = all_empty_cells[idx];
            if (switch_map[cell.first][cell.second] == -1) {
                switch_map[cell.first][cell.second] = s;
                switches.push_back({cell.first, cell.second, s});
                break;
            }
            attempts++;
        }
    }

    int current_T = calc_T();
    int best_T = current_T;
    vector<Door> best_doors = doors;
    vector<Switch> best_switches = switches;

    // 焼きなまし法の設定
    auto start_time = chrono::steady_clock::now();
    double duration = 1.9;
    double T_0 = 50.0;
    double T_f = 0.01;

    int weights[] = {10, 10, 5, 10, 10, 5, 20, 20, 10, 10};
    int total_weight = 110;

    long long iterations = 0;
    double elapsed = 0.0;
    double temp = T_0;

    while (true) {
        if ((iterations & 31) == 0) {
            auto now = chrono::steady_clock::now();
            elapsed = chrono::duration_cast<chrono::microseconds>(now - start_time).count() / 1e6;
            if (elapsed >= duration) break;
            temp = T_0 * pow(T_f / T_0, elapsed / duration);
        }
        iterations++;

        int r = rng() % total_weight;
        int op = 0;
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += weights[i];
            if (r < sum) {
                op = i;
                break;
            }
        }

        if (op == 0 && doors.size() < M) { // 扉追加 (2k+1 のみ)
            int idx = rng() % all_edges.size();
            Edge e = all_edges[idx];
            if ((e.d == 0 && door_h[e.i][e.j] == -1) || (e.d == 1 && door_v[e.i][e.j] == -1)) {
                int g = (rng() % K) * 2 + 1; // 常に奇数タイプ
                if (e.d == 0) door_h[e.i][e.j] = g;
                else door_v[e.i][e.j] = g;
                doors.push_back({e.d, e.i, e.j, g});

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    if (e.d == 0) door_h[e.i][e.j] = -1;
                    else door_v[e.i][e.j] = -1;
                    doors.pop_back();
                }
            }
        } else if (op == 1 && doors.size() > num_fixed) { // 扉削除
            int idx = num_fixed + (rng() % (doors.size() - num_fixed));
            Door old_door = doors[idx];
            if (old_door.d == 0) door_h[old_door.i][old_door.j] = -1;
            else door_v[old_door.i][old_door.j] = -1;
            doors.erase(doors.begin() + idx);

            int next_T = calc_T();
            if (next_T > 0 && accept(next_T, current_T, temp)) {
                current_T = next_T;
                if (current_T > best_T) {
                    best_T = current_T;
                    best_doors = doors;
                    best_switches = switches;
                }
            } else {
                if (old_door.d == 0) door_h[old_door.i][old_door.j] = old_door.g;
                else door_v[old_door.i][old_door.j] = old_door.g;
                doors.insert(doors.begin() + idx, old_door);
            }
        } else if (op == 2 && doors.size() > num_fixed) { // 扉型変更 (2k+1 のみ)
            int idx = num_fixed + (rng() % (doors.size() - num_fixed));
            Door old_door = doors[idx];
            int new_g = (rng() % K) * 2 + 1; // 常に奇数タイプ
            if (new_g != old_door.g) {
                if (old_door.d == 0) door_h[old_door.i][old_door.j] = new_g;
                else door_v[old_door.i][old_door.j] = new_g;
                doors[idx].g = new_g;

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    if (old_door.d == 0) door_h[old_door.i][old_door.j] = old_door.g;
                    else door_v[old_door.i][old_door.j] = old_door.g;
                    doors[idx].g = old_door.g;
                }
            }
        } else if (op == 3 && switches.size() < all_empty_cells.size()) { // スイッチ追加
            int idx = rng() % all_empty_cells.size();
            auto cell = all_empty_cells[idx];
            if (switch_map[cell.first][cell.second] == -1) {
                int s = rng() % K;
                switch_map[cell.first][cell.second] = s;
                switches.push_back({cell.first, cell.second, s});

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    switch_map[cell.first][cell.second] = -1;
                    switches.pop_back();
                }
            }
        } else if (op == 4 && !switches.empty()) { // スイッチ削除
            int idx = rng() % switches.size();
            Switch old_sw = switches[idx];
            switch_map[old_sw.i][old_sw.j] = -1;
            switches.erase(switches.begin() + idx);

            int next_T = calc_T();
            if (next_T > 0 && accept(next_T, current_T, temp)) {
                current_T = next_T;
                if (current_T > best_T) {
                    best_T = current_T;
                    best_doors = doors;
                    best_switches = switches;
                }
            } else {
                switch_map[old_sw.i][old_sw.j] = old_sw.s;
                switches.insert(switches.begin() + idx, old_sw);
            }
        } else if (op == 5 && !switches.empty()) { // スイッチ型変更
            int idx = rng() % switches.size();
            Switch old_sw = switches[idx];
            int new_s = rng() % K;
            if (new_s != old_sw.s) {
                switch_map[old_sw.i][old_sw.j] = new_s;
                switches[idx].s = new_s;

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    switch_map[old_sw.i][old_sw.j] = old_sw.s;
                    switches[idx].s = old_sw.s;
                }
            }
        } else if (op == 6 && doors.size() < M && switches.size() < all_empty_cells.size()) { // ペア追加 (2k+1 のみ)
            int e_idx = rng() % all_edges.size();
            Edge e = all_edges[e_idx];
            int c_idx = rng() % all_empty_cells.size();
            auto cell = all_empty_cells[c_idx];

            if (((e.d == 0 && door_h[e.i][e.j] == -1) || (e.d == 1 && door_v[e.i][e.j] == -1)) &&
                switch_map[cell.first][cell.second] == -1) {
                int g = (rng() % K) * 2 + 1; // 常に奇数タイプ
                int s = g / 2;

                if (e.d == 0) door_h[e.i][e.j] = g;
                else door_v[e.i][e.j] = g;
                doors.push_back({e.d, e.i, e.j, g});

                switch_map[cell.first][cell.second] = s;
                switches.push_back({cell.first, cell.second, s});

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    if (e.d == 0) door_h[e.i][e.j] = -1;
                    else door_v[e.i][e.j] = -1;
                    doors.pop_back();

                    switch_map[cell.first][cell.second] = -1;
                    switches.pop_back();
                }
            }
        } else if (op == 7 && doors.size() > num_fixed && !switches.empty()) { // ペア削除
            int d_idx = num_fixed + (rng() % (doors.size() - num_fixed));
            Door old_door = doors[d_idx];
            int target_s = old_door.g / 2;

            vector<int> matching_switches;
            for (int i = 0; i < (int)switches.size(); ++i) {
                if (switches[i].s == target_s) {
                    matching_switches.push_back(i);
                }
            }

            if (!matching_switches.empty()) {
                int s_idx_in_match = rng() % matching_switches.size();
                int s_idx = matching_switches[s_idx_in_match];
                Switch old_sw = switches[s_idx];

                if (old_door.d == 0) door_h[old_door.i][old_door.j] = -1;
                else door_v[old_door.i][old_door.j] = -1;
                doors.erase(doors.begin() + d_idx);

                switch_map[old_sw.i][old_sw.j] = -1;
                switches.erase(switches.begin() + s_idx);

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    if (old_door.d == 0) door_h[old_door.i][old_door.j] = old_door.g;
                    else door_v[old_door.i][old_door.j] = old_door.g;
                    doors.insert(doors.begin() + d_idx, old_door);

                    switch_map[old_sw.i][old_sw.j] = old_sw.s;
                    switches.insert(switches.begin() + s_idx, old_sw);
                }
            }
        } else if (op == 8 && !switches.empty()) { // スイッチ移動
            int idx = rng() % switches.size();
            Switch old_sw = switches[idx];
            int c_idx = rng() % all_empty_cells.size();
            auto cell = all_empty_cells[c_idx];

            if (switch_map[cell.first][cell.second] == -1) {
                switch_map[old_sw.i][old_sw.j] = -1;
                switch_map[cell.first][cell.second] = old_sw.s;
                switches[idx].i = cell.first;
                switches[idx].j = cell.second;

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    switch_map[cell.first][cell.second] = -1;
                    switch_map[old_sw.i][old_sw.j] = old_sw.s;
                    switches[idx].i = old_sw.i;
                    switches[idx].j = old_sw.j;
                }
            }
        } else if (op == 9 && doors.size() > num_fixed) { // 扉移動
            int idx = num_fixed + (rng() % (doors.size() - num_fixed));
            Door old_door = doors[idx];
            int e_idx = rng() % all_edges.size();
            Edge e = all_edges[e_idx];

            if ((e.d == 0 && door_h[e.i][e.j] == -1) || (e.d == 1 && door_v[e.i][e.j] == -1)) {
                if (old_door.d == 0) door_h[old_door.i][old_door.j] = -1;
                else door_v[old_door.i][old_door.j] = -1;

                if (e.d == 0) door_h[e.i][e.j] = old_door.g;
                else door_v[e.i][e.j] = old_door.g;

                doors[idx].d = e.d;
                doors[idx].i = e.i;
                doors[idx].j = e.j;

                int next_T = calc_T();
                if (next_T > 0 && accept(next_T, current_T, temp)) {
                    current_T = next_T;
                    if (current_T > best_T) {
                        best_T = current_T;
                        best_doors = doors;
                        best_switches = switches;
                    }
                } else {
                    if (e.d == 0) door_h[e.i][e.j] = -1;
                    else door_v[e.i][e.j] = -1;

                    if (old_door.d == 0) door_h[old_door.i][old_door.j] = old_door.g;
                    else door_v[old_door.i][old_door.j] = old_door.g;

                    doors[idx] = old_door;
                }
            }
        }
    }

    // 最高得点配置を出力
    cout << best_doors.size() << "\n";
    for (const auto& d : best_doors) {
        cout << d.d << " " << d.i << " " << d.j << " " << d.g << "\n";
    }
    cout << best_switches.size() << "\n";
    for (const auto& s : best_switches) {
        cout << s.i << " " << s.j << " " << s.s << "\n";
    }

    return 0;
}