
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 20;

struct Pos {
    int r, c;
    bool operator==(const Pos& other) const { return r == other.r && c == other.c; }
};

int grid[N][N];
Pos box_pos[N * N];
vector<vector<Pos>> loops;
vector<pair<int, int>> ops;
int next_box_to_remove = 0;

void update_pos(int v, int r, int c) {
    if (v != -1) {
        box_pos[v] = {r, c};
    }
}

void apply_op(int m, int d) {
    ops.push_back({m, d});
    const auto& loop = loops[m];
    int l = loop.size();
    vector<int> prev_values(l);
    for (int i = 0; i < l; ++i) prev_values[i] = grid[loop[i].r][loop[i].c];
    for (int i = 0; i < l; ++i) {
        int next_idx = (i + d + l) % l;
        int v = prev_values[i];
        grid[loop[next_idx].r][loop[next_idx].c] = v;
        update_pos(v, loop[next_idx].r, loop[next_idx].c);
    }
    // Check removal
    while (next_box_to_remove < N * N) {
        if (grid[0][10] == next_box_to_remove) {
            grid[0][10] = -1;
            box_pos[next_box_to_remove] = {-1, -1};
            next_box_to_remove++;
        } else {
            break;
        }
    }
}

int main() {
    int dummy_n;
    if (!(cin >> dummy_n)) return 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            update_pos(grid[i][j], i, j);
        }
    }

    // Define Loop 0 (Top loop)
    vector<Pos> loop0;
    for (int j = 0; j < N; ++j) loop0.push_back({0, j});
    for (int j = N - 1; j >= 0; --j) loop0.push_back({1, j});
    loops.push_back(loop0);

    // Define Vertical Loops
    for (int j = 0; j < 10; ++j) {
        vector<Pos> vloop;
        for (int r = 1; r < N; ++r) vloop.push_back({r, 2 * j});
        vloop.push_back({N - 1, 2 * j + 1});
        for (int r = N - 2; r >= 1; --r) vloop.push_back({r, 2 * j + 1});
        loops.push_back(vloop);
    }

    // Initial removal check
    while (next_box_to_remove < N * N) {
        if (grid[0][10] == next_box_to_remove) {
            grid[0][10] = -1;
            box_pos[next_box_to_remove] = {-1, -1};
            next_box_to_remove++;
        } else {
            break;
        }
    }

    while (next_box_to_remove < N * N) {
        int batch_start = next_box_to_remove;
        int batch_end = min(batch_start + 19, N * N - 1);
        vector<int> current_batch;
        for (int v = batch_start; v <= batch_end; ++v) {
            if (box_pos[v].r != -1) current_batch.push_back(v);
        }

        set<int> in_loop0_targets;
        for (int v : current_batch) {
            if (box_pos[v].r != -1 && box_pos[v].r < 2) {
                in_loop0_targets.insert(v);
            }
        }

        // Phase 1: Bring batch boxes from vertical loops to Loop 0
        for (int v : current_batch) {
            Pos p = box_pos[v];
            if (p.r == -1 || p.r < 2) continue;

            int j = p.c / 2;
            int m = j + 1;

            // Rotate Loop 0 to free up contact points with vloop
            int best_rot = -1;
            for (int r0 = 0; r0 < 40; ++r0) {
                int idx1 = (39 - 2 * j - r0 + 40) % 40;
                int idx2 = (38 - 2 * j - r0 + 40) % 40;

                int b1 = grid[loops[0][idx1].r][loops[0][idx1].c];
                int b2 = grid[loops[0][idx2].r][loops[0][idx2].c];

                if (in_loop0_targets.count(b1) == 0 && in_loop0_targets.count(b2) == 0) {
                    best_rot = r0;
                    break;
                }
            }

            if (best_rot != -1) {
                int steps = (best_rot <= 30) ? best_rot : (best_rot - 40);
                if (steps > 0)
                    for (int k = 0; k < steps; ++k) apply_op(0, 1);
                else
                    for (int k = 0; k < -steps; ++k) apply_op(0, -1);
            }

            // Rotate vloop m until v is at Row 1
            int v_idx = -1;
            int l = loops[m].size();
            for (int k = 0; k < l; ++k) {
                if (grid[loops[m][k].r][loops[m][k].c] == v) {
                    v_idx = k;
                    break;
                }
            }

            int dist_cw = v_idx;
            int dist_ccw = l - v_idx;
            if (dist_cw < dist_ccw) {
                for (int k = 0; k < dist_cw; ++k) apply_op(m, -1);
            } else {
                for (int k = 0; k < dist_ccw; ++k) apply_op(m, 1);
            }

            in_loop0_targets.insert(v);
        }

        // Phase 2: Output batch boxes in sequence
        for (int v : current_batch) {
            if (box_pos[v].r == -1) continue;

            int v_idx = -1;
            for (int k = 0; k < 40; ++k) {
                if (grid[loops[0][k].r][loops[0][k].c] == v) {
                    v_idx = k;
                    break;
                }
            }

            // Outlet is at loop0[10] = (0, 10)
            int dist = (10 - v_idx + 40) % 40;
            int steps = (dist <= 20) ? dist : (dist - 40);
            if (steps > 0)
                for (int k = 0; k < steps; ++k) apply_op(0, 1);
            else
                for (int k = 0; k < -steps; ++k) apply_op(0, -1);
        }

        if (next_box_to_remove == batch_start && !current_batch.empty()) {
            // Should not happen, but prevents infinite loop
            break;
        }
    }

    // Output belt configuration
    cout << loops.size() << endl;
    for (const auto& loop : loops) {
        cout << loop.size();
        for (const auto& p : loop) {
            cout << " " << p.r << " " << p.c;
        }
        cout << endl;
    }

    // Output operation sequence
    cout << ops.size() << endl;
    for (const auto& op : ops) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}
