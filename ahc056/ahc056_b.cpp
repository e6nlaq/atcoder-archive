#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

int N, K, T;
std::vector<std::string> v_walls;
std::vector<std::string> h_walls;
std::vector<std::pair<int, int>> destinations;
char move_dir[20][20][20][20];

int di[] = {-1, 1, 0, 0, 0};
int dj[] = {0, 0, -1, 1, 0};
char dir_char[] = {'U', 'D', 'L', 'R', 'S'};

bool is_valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

bool has_wall_check(int i, int j, int k) {
    if (k == 0) {  // up
        if (i == 0) return true;
        return h_walls[i - 1][j] == '1';
    }
    if (k == 1) {  // down
        if (i == N - 1) return true;
        return h_walls[i][j] == '1';
    }
    if (k == 2) {  // left
        if (j == 0) return true;
        return v_walls[i][j - 1] == '1';
    }
    if (k == 3) {  // right
        if (j == N - 1) return true;
        return v_walls[i][j] == '1';
    }
    return false;  // stay
}

void bfs(int start_i, int start_j) {
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, -1));
    std::vector<std::vector<int>> first_move_dir(N, std::vector<int>(N, -1));
    std::queue<std::pair<int, int>> q;

    dist[start_i][start_j] = 0;
    first_move_dir[start_i][start_j] = 4;  // stay
    q.push({start_i, start_j});

    while (!q.empty()) {
        auto [ci, cj] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (is_valid(ni, nj) && !has_wall_check(ci, cj, k) && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[ci][cj] + 1;
                if (ci == start_i && cj == start_j) {
                    first_move_dir[ni][nj] = k;
                } else {
                    first_move_dir[ni][nj] = first_move_dir[ci][cj];
                }
                q.push({ni, nj});
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] != -1) {
                move_dir[start_i][start_j][i][j] = dir_char[first_move_dir[i][j]];
            } else {
                move_dir[start_i][start_j][i][j] = 'S';
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> K >> T;
    v_walls.resize(N);
    h_walls.resize(N - 1);
    for (int i = 0; i < N; ++i) std::cin >> v_walls[i];
    for (int i = 0; i < N - 1; ++i) std::cin >> h_walls[i];
    destinations.resize(K);
    for (int i = 0; i < K; ++i) {
        std::cin >> destinations[i].first >> destinations[i].second;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bfs(i, j);
        }
    }

    std::map<std::pair<int, int>, std::set<int>> visited_pos_q;
    int sim_i = 0;
    int sim_j = 0;
    int sim_q = 0;
    int sim_steps = 0;
    while (sim_steps < T && sim_q < K) {
        visited_pos_q[{sim_i, sim_j}].insert(sim_q);
        auto& target = destinations[sim_q];
        char move = move_dir[sim_i][sim_j][target.first][target.second];

        int next_q = sim_q;
        if (sim_i == target.first && sim_j == target.second) {
            next_q++;
        }

        int move_idx = -1;
        for (int i = 0; i < 5; ++i)
            if (dir_char[i] == move) move_idx = i;

        int next_i = sim_i, next_j = sim_j;
        if (move_idx != 4 && !has_wall_check(sim_i, sim_j, move_idx)) {
            next_i = sim_i + di[move_idx];
            next_j = sim_j + dj[move_idx];
        }
        sim_i = next_i;
        sim_j = next_j;
        sim_q = next_q;
        sim_steps++;
    }
    if (sim_q == K) {
        visited_pos_q[{sim_i, sim_j}].insert(K);
    }

    std::vector<std::pair<int, int>> visited_positions;
    for(auto const& [pos, q_set] : visited_pos_q) {
        visited_positions.push_back(pos);
    }

    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> adj;
    for (size_t i = 0; i < visited_positions.size(); ++i) {
        for (size_t j = i + 1; j < visited_positions.size(); ++j) {
            auto pos1 = visited_positions[i];
            auto pos2 = visited_positions[j];
            const auto& Q1 = visited_pos_q.at(pos1);
            const auto& Q2 = visited_pos_q.at(pos2);
            
            bool conflict = false;
            for (int q : Q1) {
                if (Q2.count(q)) {
                    if (q >= K) continue;
                    char move1 = move_dir[pos1.first][pos1.second][destinations[q].first][destinations[q].second];
                    int next_q1 = (pos1 == destinations[q]) ? q + 1 : q;
                    char move2 = move_dir[pos2.first][pos2.second][destinations[q].first][destinations[q].second];
                    int next_q2 = (pos2 == destinations[q]) ? q + 1 : q;
                    if (move1 != move2 || next_q1 != next_q2) {
                        conflict = true;
                        break;
                    }
                }
            }
            if (conflict) {
                adj[pos1].push_back(pos2);
                adj[pos2].push_back(pos1);
            }
        }
    }

    std::sort(visited_positions.begin(), visited_positions.end(), [&](const auto& p1, const auto& p2){
        size_t deg1 = adj.count(p1) ? adj.at(p1).size() : 0;
        size_t deg2 = adj.count(p2) ? adj.at(p2).size() : 0;
        if (deg1 != deg2) return deg1 > deg2;
        return p1 < p2;
    });

    std::map<std::pair<int, int>, int> colors;
    int max_color = 0;
    for (const auto& pos : visited_positions) {
        std::set<int> neighbor_colors;
        if (adj.count(pos)) {
            for (const auto& neighbor : adj.at(pos)) {
                if (colors.count(neighbor)) {
                    neighbor_colors.insert(colors.at(neighbor));
                }
            }
        }
        int c = 1;
        while (neighbor_colors.count(c)) {
            c++;
        }
        colors[pos] = c;
        max_color = std::max(max_color, c);
    }

    std::vector<std::vector<int>> initial_colors(N, std::vector<int>(N, 0));
    for(const auto& [pos, color] : colors) {
        initial_colors[pos.first][pos.second] = color;
    }

    int C = max_color > 0 ? max_color + 1 : 1;
    
    std::map<std::pair<int, int>, std::tuple<int, int, char>> rules;
    for (const auto& [pos, q_set] : visited_pos_q) {
        int c = colors.at(pos);
        for (int q : q_set) {
            if (rules.count({c, q})) continue;
            if (q >= K) {
                rules[{c, q}] = {c, q, 'S'};
            } else {
                char move = move_dir[pos.first][pos.second][destinations[q].first][destinations[q].second];
                int next_q = (pos == destinations[q]) ? q + 1 : q;
                rules[{c, q}] = {c, next_q, move};
            }
        }
    }

    int max_q_in_rules = 0;
    if (!rules.empty()) {
        for (const auto& [key, val] : rules) {
            max_q_in_rules = std::max(max_q_in_rules, key.second);
            max_q_in_rules = std::max(max_q_in_rules, std::get<1>(val));
        }
    }
    int Q = max_q_in_rules + 1;

    std::cout << C << " " << Q << " " << std::min(rules.size(), (std::size_t)T) << std::endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << initial_colors[i][j] << (j == N - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    int cnt = 0;
    for (auto const& [key, val] : rules) {
        if (cnt >= T) break;
        std::cout << key.first << " " << key.second << " "
                  << std::get<0>(val) << " " << std::get<1>(val) << " "
                  << std::get<2>(val) << std::endl;
        cnt++;
    }

    return 0;
}