#include <algorithm>
#include <chrono>
#include <deque>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <vector>

using namespace std;

const int TIME_LIMIT_MS = 1700;
const int EXPANSION_PER_STATE = 20;
int BEAM_WIDTH = 80;

int N, M, C;
vector<int> target_d;

struct State {
    vector<vector<int>> board;
    vector<pair<int, int>> snake_coords;
    vector<int> snake_colors;
    string moves;
    double score;

    void calc_score() {
        int c = 0;
        int n = snake_colors.size();
        for (int i = 0; i < min((int)target_d.size(), n); ++i) {
            if (target_d[i] == snake_colors[i]) {
                c++;
            }
        }
        score = 100000.0 * c / n - 150.0 * (M - n) - moves.size();
    }

    double true_score() const {
        int E = 0;
        int k = snake_colors.size();
        for (int i = 0; i < k; ++i) {
            if (i >= (int)target_d.size() || snake_colors[i] != target_d[i]) {
                E++;
            }
        }
        return moves.length() + 10000.0 * (E + 2.0 * max(0, (int)target_d.size() - k));
    }

    bool operator<(const State& o) const {
        if (score > o.score) return true;
        if (score < o.score) return false;
        return snake_colors.size() > o.snake_colors.size();
    }
};

bool simulate_step(State& S, char dir) {
    int dx = 0, dy = 0;
    if (dir == 'U') {
        dx = -1;
        dy = 0;
    } else if (dir == 'D') {
        dx = 1;
        dy = 0;
    } else if (dir == 'L') {
        dx = 0;
        dy = -1;
    } else if (dir == 'R') {
        dx = 0;
        dy = 1;
    }

    int r = S.snake_coords[0].first;
    int c = S.snake_coords[0].second;
    int nr = r + dx;
    int nc = c + dy;

    if (nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
    if (S.snake_coords.size() > 1 && S.snake_coords[1] == make_pair(nr, nc)) return false;

    int k = S.snake_coords.size();
    vector<pair<int, int>> new_coords(k);
    new_coords[0] = {nr, nc};
    for (int i = 1; i < k; ++i) {
        new_coords[i] = S.snake_coords[i - 1];
    }

    int h = -1;
    for (int i = 1; i < k; ++i) {
        if (new_coords[i] == make_pair(nr, nc)) {
            h = i;
            break;
        }
    }

    if (h != -1) {
        for (int p = h + 1; p < k; ++p) {
            S.board[new_coords[p].first][new_coords[p].second] = S.snake_colors[p];
        }
        new_coords.resize(h + 1);
        S.snake_colors.resize(h + 1);
    } else {
        if (S.board[nr][nc] > 0) {
            int c_prime = S.board[nr][nc];
            S.board[nr][nc] = 0;
            new_coords.push_back(S.snake_coords[k - 1]);
            S.snake_colors.push_back(c_prime);
        }
    }
    S.snake_coords.assign(new_coords.begin(), new_coords.end());
    S.moves += dir;
    return true;
}

struct BFS_Node {
    int r, c;
    string path;
};

vector<string> find_food_paths(const State& S) {
    vector<string> paths;
    int start_r = S.snake_coords[0].first;
    int start_c = S.snake_coords[0].second;
    int k = S.snake_coords.size();

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<bool>> obstacle(N, vector<bool>(N, false));
    for (int i = 1; i < k - 1; ++i) {
        obstacle[S.snake_coords[i].first][S.snake_coords[i].second] = true;
    }

    queue<BFS_Node> q;
    q.push({start_r, start_c, ""});
    visited[start_r][start_c] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir_char[] = {'U', 'D', 'L', 'R'};

    while (!q.empty()) {
        auto [r, c, path] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (path.empty() && k > 1 && make_pair(nr, nc) == S.snake_coords[1]) continue;

            if (visited[nr][nc]) continue;
            visited[nr][nc] = true;

            if (obstacle[nr][nc]) continue;

            if (S.board[nr][nc] > 0) {
                paths.push_back(path + dir_char[i]);
            } else {
                q.push({nr, nc, path + dir_char[i]});
            }
        }
    }
    return paths;
}

vector<char> get_non_biting_dirs(const State& S) {
    int r = S.snake_coords[0].first;
    int c = S.snake_coords[0].second;
    vector<char> dirs;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir_char[] = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        bool is_body = false;
        // 自分を噛まないために、現存する胴体（1〜k-1）を避ける
        for (int j = 1; j < (int)S.snake_coords.size(); ++j) {
            if (S.snake_coords[j] == make_pair(nr, nc)) {
                is_body = true;
                break;
            }
        }
        if (!is_body) dirs.push_back(dir_char[i]);
    }
    return dirs;
}

char random_valid_dir(const State& S, mt19937& rng) {
    int r = S.snake_coords[0].first;
    int c = S.snake_coords[0].second;
    vector<char> dirs;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir_char[] = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (S.snake_coords.size() > 1 && make_pair(nr, nc) == S.snake_coords[1]) continue;
        dirs.push_back(dir_char[i]);
    }
    if (dirs.empty()) return 'X';
    return dirs[rng() % dirs.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start_time = chrono::high_resolution_clock::now();
    mt19937 rng(42);

    if (!(cin >> N >> M >> C)) return 0;

    BEAM_WIDTH = 5 + (1 - double(M) / double(N * N)) * 100;

    target_d.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> target_d[i];
    }

    State initial_state;
    initial_state.board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            cin >> initial_state.board[i][j];
        }
    }

    for (int i = 4; i >= 0; --i) {
        initial_state.snake_coords.push_back({i, 0});
    }
    initial_state.snake_colors.assign(5, 1);
    initial_state.moves = "";
    initial_state.calc_score();

    vector<State> beam;
    beam.push_back(initial_state);

    State best_overall = initial_state;

    while (true) {
        auto current_time = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> diff = current_time - start_time;
        if (diff.count() > TIME_LIMIT_MS) break;

        vector<State> next_beam;
        bool all_stuck = true;

        for (const State& S : beam) {
            vector<string> food_paths = find_food_paths(S);

            if (!food_paths.empty()) {
                all_stuck = false;
                std::shuffle(food_paths.begin(), food_paths.end(), rng);
                int take = min((int)food_paths.size(), EXPANSION_PER_STATE);
                for (int i = 0; i < take; ++i) {
                    State nxt = S;
                    bool ok = true;
                    for (char d : food_paths[i]) {
                        if (!simulate_step(nxt, d)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        nxt.calc_score();
                        next_beam.push_back(nxt);
                        double ts = nxt.true_score();
                        if (ts < best_overall.true_score()) {
                            best_overall = nxt;
                        } else if (abs(ts - best_overall.true_score()) < 1e-9 && nxt.moves.length() < best_overall.moves.length()) {
                            best_overall = nxt;
                        }
                    }
                }
            } else {
                all_stuck = false;
                for (int i = 0; i < EXPANSION_PER_STATE; ++i) {
                    State nxt = S;
                    // 自分をかまないランダムウォーク(max200手)
                    for (int step = 0; step < 200; ++step) {
                        if (!find_food_paths(nxt).empty()) break;
                        vector<char> safe = get_non_biting_dirs(nxt);
                        if (safe.empty()) break;
                        simulate_step(nxt, safe[rng() % safe.size()]);
                    }
                    // それでもエサが見つからなければ自分を噛むことを許可するランダムウォーク
                    if (find_food_paths(nxt).empty()) {
                        for (int step = 0; step < 10; ++step) {
                            char d = random_valid_dir(nxt, rng);
                            if (d == 'X') break;
                            int old_k = nxt.snake_colors.size();
                            simulate_step(nxt, d);
                            if (nxt.snake_colors.size() < old_k) break;
                        }
                    }
                    nxt.calc_score();
                    next_beam.push_back(nxt);
                    // ここで全生成状態に対して実スコアの過去最高をチェック
                    double ts = nxt.true_score();
                    if (ts < best_overall.true_score()) {
                        best_overall = nxt;
                    } else if (abs(ts - best_overall.true_score()) < 1e-9 && nxt.moves.length() < best_overall.moves.length()) {
                        best_overall = nxt;
                    }
                }
            }
        }

        if (next_beam.empty() || all_stuck) break;

        std::sort(next_beam.begin(), next_beam.end());

        beam.clear();
        int take = min((int)next_beam.size(), BEAM_WIDTH);
        beam.insert(beam.end(), next_beam.begin(), next_beam.begin() + take);
    }

    // 残りのエサを貪欲にすべて回収するフェーズ
    while (best_overall.snake_colors.size() < M && best_overall.moves.length() < 95000) {
        vector<string> food_paths = find_food_paths(best_overall);
        if (!food_paths.empty()) {
            string best_path = food_paths[0];
            for (const string& p : food_paths) {
                if (p.length() < best_path.length()) {
                    best_path = p;
                }
            }
            for (char d : best_path) {
                simulate_step(best_overall, d);
            }
        } else {
            // 自分をかまないランダムウォーク
            for (int step = 0; step < 200; ++step) {
                if (!find_food_paths(best_overall).empty()) break;
                vector<char> safe = get_non_biting_dirs(best_overall);
                if (safe.empty()) break;
                simulate_step(best_overall, safe[rng() % safe.size()]);
            }
            // それでもダメなら自分を噛む
            if (find_food_paths(best_overall).empty()) {
                for (int step = 0; step < 10; ++step) {
                    char d = random_valid_dir(best_overall, rng);
                    if (d == 'X') break;
                    int old_k = best_overall.snake_colors.size();
                    simulate_step(best_overall, d);
                    if (best_overall.snake_colors.size() < old_k) break;
                }
            }
        }
    }

    for (char c : best_overall.moves) {
        cout << c << "\n";
    }

    return 0;
}
