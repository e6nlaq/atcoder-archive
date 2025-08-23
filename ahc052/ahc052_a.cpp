#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
#include <chrono>
#include <cmath>
#include <cstddef>

// Constants
const int N = 30;
const int M = 10;
const int K = 10;
const int MAX_TURNS = 2 * N * N;
const double TIME_LIMIT_MS = 1900.0;

// Globals (read-only for solver)
std::vector<std::string> v_walls(N);
std::vector<std::string> h_walls(N - 1);
std::vector<std::pair<int, int>> initial_robot_pos(M);
int initial_waxed_count = 0;
std::vector<std::vector<bool>> initial_waxed(N, std::vector<bool>(N, false));

// Random number generator
std::mt19937 rng(std::random_device{}());

// --- Forward declarations ---
std::pair<int, std::vector<int>> run_greedy_solver(const std::vector<std::vector<char>>& button_config);
std::pair<int, int> get_next_pos(const std::pair<int, int>& robot_pos, char move);
std::vector<std::vector<int>> calculate_distance_to_unwaxed(const std::vector<std::vector<bool>>& waxed);


int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    auto start_time = std::chrono::high_resolution_clock::now();

    // --- Input ---
    int n_in, m_in, k_in;
    std::cin >> n_in >> m_in >> k_in;
    for (int i = 0; i < M; ++i) {
        std::cin >> initial_robot_pos[i].first >> initial_robot_pos[i].second;
        if (!initial_waxed[initial_robot_pos[i].first][initial_robot_pos[i].second]) {
            initial_waxed[initial_robot_pos[i].first][initial_robot_pos[i].second] = true;
            initial_waxed_count++;
        }
    }
    for (int i = 0; i < N; ++i) std::cin >> v_walls[i];
    for (int i = 0; i < N - 1; ++i) std::cin >> h_walls[i];

    // --- Simulated Annealing for Button Configuration ---
    const char moves[] = {'U', 'D', 'L', 'R', 'S'};
    
    // Generate initial heuristic config
    std::vector<std::vector<char>> current_config(K, std::vector<char>(M));
    for (int j = 0; j < M; ++j) current_config[0][j] = 'U';
    for (int j = 0; j < M; ++j) current_config[1][j] = 'D';
    for (int j = 0; j < M; ++j) current_config[2][j] = 'L';
    for (int j = 0; j < M; ++j) current_config[3][j] = 'R';
    for (int j = 0; j < M; ++j) current_config[4][j] = (j % 2 == 0) ? 'R' : 'L';
    for (int j = 0; j < M; ++j) current_config[5][j] = (j % 2 == 0) ? 'L' : 'R';
    for (int j = 0; j < M; ++j) current_config[6][j] = (j % 2 == 0) ? 'D' : 'U';
    for (int j = 0; j < M; ++j) current_config[7][j] = (j % 2 == 0) ? 'U' : 'D';
    std::uniform_int_distribution<int> move_dist(0, 4);
    for (int i = 8; i < K; ++i) {
        for (int j = 0; j < M; ++j) {
            current_config[i][j] = moves[move_dist(rng)];
        }
    }

    auto eval_result = run_greedy_solver(current_config);
    int current_score = eval_result.first;
    
    auto best_config = current_config;
    int best_score = current_score;
    auto best_actions = eval_result.second;

    double temperature = 50.0;
    double cooling_rate = 0.999;
    std::uniform_real_distribution<double> prob_dist(0.0, 1.0);

    while (true) {
        auto now = std::chrono::high_resolution_clock::now();
        double elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
        if (elapsed_ms > TIME_LIMIT_MS) {
            break;
        }

        std::vector<std::vector<char>> new_config = current_config;
        
        // Perturb
        std::uniform_int_distribution<int> k_dist(0, K - 1);
        std::uniform_int_distribution<int> m_dist(0, M - 1);
        new_config[k_dist(rng)][m_dist(rng)] = moves[move_dist(rng)];

        auto new_eval = run_greedy_solver(new_config);
        int new_score = new_eval.first;

        if (new_score > current_score) {
            current_score = new_score;
            current_config = new_config;
            if (new_score > best_score) {
                best_score = new_score;
                best_config = new_config;
                best_actions = new_eval.second;
            }
        } else {
            double p = exp((double)(new_score - current_score) / temperature);
            if (prob_dist(rng) < p) {
                current_score = new_score;
                current_config = new_config;
            }
        }
        
        temperature *= cooling_rate;
    }

    // --- Final Output ---
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << best_config[i][j] << (j == M - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    for (const auto& action : best_actions) {
        std::cout << action << std::endl;
    }

    return 0;
}


// --- Solver Implementation ---
std::pair<int, std::vector<int>> run_greedy_solver(const std::vector<std::vector<char>>& button_config) {
    std::vector<std::pair<int, int>> robot_pos = initial_robot_pos;
    std::vector<std::vector<bool>> waxed = initial_waxed;
    int waxed_count = initial_waxed_count;
    
    std::vector<int> actions;
    int stuck_turns_counter = 0;

    for (int turn = 0; turn < MAX_TURNS && waxed_count < N * N; ++turn) {
        int best_button = -1;
        int max_new_cells = -1;
        std::vector<std::pair<int, int>> best_next_pos;

        for (int k = 0; k < K; ++k) {
            std::vector<std::pair<int, int>> next_pos(M);
            int distinct_new_cells = 0;
            std::vector<std::vector<bool>> temp_waxed = waxed;

            for (int j = 0; j < M; ++j) {
                next_pos[j] = get_next_pos(robot_pos[j], button_config[k][j]);
                if (!temp_waxed[next_pos[j].first][next_pos[j].second]) {
                    temp_waxed[next_pos[j].first][next_pos[j].second] = true;
                    distinct_new_cells++;
                }
            }

            if (distinct_new_cells > max_new_cells) {
                max_new_cells = distinct_new_cells;
                best_button = k;
                best_next_pos = next_pos;
            }
        }

        if (max_new_cells > 0) {
            stuck_turns_counter = 0;
        }

        if (max_new_cells <= 0) {
            stuck_turns_counter++;
            if (stuck_turns_counter > 5) {
                std::uniform_int_distribution<int> random_button_dist(8, K - 1);
                best_button = random_button_dist(rng);
                best_next_pos.resize(M);
                for (int j = 0; j < M; ++j) {
                    best_next_pos[j] = get_next_pos(robot_pos[j], button_config[best_button][j]);
                }
                stuck_turns_counter = 0;
            } else {
                auto dist_map = calculate_distance_to_unwaxed(waxed);
                std::vector<std::vector<bool>> is_frontier(N, std::vector<bool>(N, false));
                int dr[] = {-1, 1, 0, 0}; int dc[] = {0, 0, -1, 1};
                for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) if (waxed[r][c]) {
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !waxed[nr][nc]) {
                            bool wall = false;
                            if (dr[i] == -1) { if (h_walls[r - 1][c] == '1') wall = true; }
                            else if (dr[i] == 1) { if (h_walls[r][c] == '1') wall = true; }
                            else if (dc[i] == -1) { if (v_walls[r][c - 1] == '1') wall = true; }
                            else if (dc[i] == 1) { if (v_walls[r][c] == '1') wall = true; }
                            if (!wall) { is_frontier[r][c] = true; break; }
                        }
                    }
                }
                long long best_score = -1; const int FRONTIER_BONUS = N;
                for (int k = 0; k < K; ++k) {
                    std::vector<std::pair<int, int>> next_pos(M);
                    long long current_dist = 0; int frontier_robots = 0;
                    for (int j = 0; j < M; ++j) {
                        next_pos[j] = get_next_pos(robot_pos[j], button_config[k][j]);
                        if (dist_map[next_pos[j].first][next_pos[j].second] != -1) current_dist += dist_map[next_pos[j].first][next_pos[j].second];
                        else current_dist += N * N;
                        if (is_frontier[next_pos[j].first][next_pos[j].second]) frontier_robots++;
                    }
                    long long final_score = current_dist - (long long)frontier_robots * FRONTIER_BONUS;
                    if (best_score == -1 || final_score < best_score) {
                        best_score = final_score; best_button = k; best_next_pos = next_pos;
                    }
                }
            }
        }
        actions.push_back(best_button);
        robot_pos = best_next_pos;
        for (const auto& pos : robot_pos) if (!waxed[pos.first][pos.second]) {
            waxed[pos.first][pos.second] = true;
            waxed_count++;
        }
    }

    int final_score = (waxed_count == N * N) ? (3 * N * N - actions.size()) : (N * N - (N * N - waxed_count));
    return {final_score, actions};
}

std::pair<int, int> get_next_pos(const std::pair<int, int>& robot_pos, char move) {
    auto [r, c] = robot_pos; int nr = r, nc = c;
    if (move == 'U') { if (r > 0 && h_walls[r - 1][c] == '0') nr--; }
    else if (move == 'D') { if (r < N - 1 && h_walls[r][c] == '0') nr++; }
    else if (move == 'L') { if (c > 0 && v_walls[r][c - 1] == '0') nc--; }
    else if (move == 'R') { if (c < N - 1 && v_walls[r][c] == '0') nc++; }
    return {nr, nc};
}

std::vector<std::vector<int>> calculate_distance_to_unwaxed(const std::vector<std::vector<bool>>& waxed) {
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, -1));
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (!waxed[i][j]) { q.push({i, j}); dist[i][j] = 0; }
    int dr[] = {-1, 1, 0, 0}; int dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && dist[nr][nc] == -1) {
                bool wall = false;
                if (dr[i] == -1) { if (h_walls[r - 1][c] == '1') wall = true; }
                else if (dr[i] == 1) { if (h_walls[r][c] == '1') wall = true; }
                else if (dc[i] == -1) { if (v_walls[r][c - 1] == '1') wall = true; }
                else if (dc[i] == 1) { if (v_walls[r][c] == '1') wall = true; }
                if (!wall) { dist[nr][nc] = dist[r][c] + 1; q.push({nr, nc}); }
            }
        }
    }
    return dist;
}
