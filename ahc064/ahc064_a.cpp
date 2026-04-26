#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/**
 * AHC064 高橋鉄道 (Sorting Railway Cars)
 * 
 * 並列化・0分割 基数ソート (Parallel 0-split Radix Sort)
 * 交差条件と安定性条件を満たす範囲で、同時に複数の車両を移動させます。
 */

struct Move {
    int type; // 0: D->W, 1: W->D
    int i, j, k;
};

int R = 10;
vector<deque<int>> departure(10);
vector<deque<int>> waiting(10);
vector<vector<Move>> turns;

void execute_turn(const vector<Move>& moves) {
    if (moves.empty()) return;
    turns.push_back(moves);
    for (const auto& m : moves) {
        if (m.type == 0) { // D -> W
            vector<int> block;
            for (int x = 0; x < m.k; ++x) {
                block.push_back(departure[m.i].back());
                departure[m.i].pop_back();
            }
            reverse(block.begin(), block.end());
            for (int v_idx = (int)block.size() - 1; v_idx >= 0; --v_idx) {
                waiting[m.j].push_front(block[v_idx]);
            }
        } else { // W -> D
            for (int x = 0; x < m.k; ++x) {
                int val = waiting[m.j].front();
                waiting[m.j].pop_front();
                departure[m.i].push_back(val);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input_R;
    if (!(cin >> input_R)) return 0;

    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            int id;
            cin >> id;
            departure[r].push_back(id);
        }
    }

    vector<int> src_D = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Pass 1: D -> W (基数ソート: 1の位)
    while (true) {
        vector<Move> turn;
        int last_w = 10;
        vector<bool> blocked_w(10, false);
        
        for (int idx = 9; idx >= 0; --idx) {
            int i = src_D[idx];
            if (departure[i].empty()) continue;
            
            int val = departure[i].back();
            int d = val % 10;
            
            int k = 0;
            if (d < last_w && !blocked_w[d]) {
                k = 1;
                while (k < (int)departure[i].size() && (departure[i][departure[i].size() - 1 - k] % 10) == d) k++;
                
                turn.push_back({0, i, d, k});
                last_w = d; 
            }
            
            // 安定性を保つため、この出発線に残る全車両の目的地をブロックする
            // これにより、より前方の出発線が同じ目的地に先回りすることを防ぐ
            for (int x = 0; x < (int)departure[i].size() - k; ++x) {
                blocked_w[departure[i][x] % 10] = true;
            }
        }
        
        if (turn.empty()) break;
        execute_turn(turn);
    }

    // Collect Pass 1: W -> src_D (安定性を保つため W0 から順番に回収)
    int curr_d = 0;
    int curr_src_idx = 0;
    while (curr_d < 10) {
        if (waiting[curr_d].empty()) {
            curr_d++;
            continue;
        }
        int target_D = src_D[curr_src_idx];
        if ((int)departure[target_D].size() == 15) {
            curr_src_idx++;
            target_D = src_D[curr_src_idx];
        }
        int space = 15 - (int)departure[target_D].size();
        int k = min((int)waiting[curr_d].size(), space);
        execute_turn({{1, target_D, curr_d, k}});
    }

    // Pass 2: D -> W (基数ソート: 10の位)
    while (true) {
        vector<Move> turn;
        int last_w = 10;
        vector<bool> blocked_w(10, false);
        
        for (int idx = 9; idx >= 0; --idx) {
            int i = src_D[idx];
            if (departure[i].empty()) continue;
            
            int val = departure[i].back();
            int d = val / 10;
            
            int k = 0;
            if (d < last_w && !blocked_w[d]) {
                k = 1;
                while (k < (int)departure[i].size() && (departure[i][departure[i].size() - 1 - k] / 10) == d) k++;
                
                turn.push_back({0, i, d, k});
                last_w = d;
            }
            
            for (int x = 0; x < (int)departure[i].size() - k; ++x) {
                blocked_w[departure[i][x] / 10] = true;
            }
        }
        
        if (turn.empty()) break;
        execute_turn(turn);
    }

    // Final Placement: W -> 目標の出発線
    // i = d, j = d であるため全く交差しない。1ターンで全列同時に移動。
    vector<Move> final_turn;
    for (int d = 0; d <= 9; ++d) {
        if (!waiting[d].empty()) {
            int k = (int)waiting[d].size();
            final_turn.push_back({1, d, d, k});
        }
    }
    if (!final_turn.empty()) {
        execute_turn(final_turn);
    }

    cout << turns.size() << "\n";
    for (const auto& turn : turns) {
        cout << turn.size() << "\n";
        for (const auto& m : turn) cout << m.type << " " << m.i << " " << m.j << " " << m.k << "\n";
    }

    return 0;
}
