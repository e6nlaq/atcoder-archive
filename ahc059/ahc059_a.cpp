#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 20;
const double TIME_LIMIT = 1.90;

// Block settings
const int BLOCK_H = 2;
const int BLOCK_W = 2;
const int BLOCKS_R = N / BLOCK_H;
const int BLOCKS_C = N / BLOCK_W;
const int NUM_BLOCKS = BLOCKS_R * BLOCKS_C;
const int MAX_BLOCK_CAPACITY = BLOCK_H * BLOCK_W;  // Max cards a block can hold at once

struct Pos {
    int r, c;
    int dist(const Pos& other) const {
        return abs(r - other.r) + abs(c - other.c);
    }
    bool operator==(const Pos& other) const { return r == other.r && c == other.c; }
};

struct Block {
    int id;
    int r_min, c_min;
    Pos center;

    void init(int _id) {
        id = _id;
        int br = id / BLOCKS_C;
        int bc = id % BLOCKS_C;
        r_min = br * BLOCK_H;
        c_min = bc * BLOCK_W;
        center = {r_min + BLOCK_H / 2, c_min + BLOCK_W / 2};
    }

    bool contains(Pos p) const {
        return p.r >= r_min && p.r < r_min + BLOCK_H && p.c >= c_min && p.c < c_min + BLOCK_W;
    }
};

Block blocks[NUM_BLOCKS];

// Global state
int initial_grid[N][N];
string ops = "";
Pos curr_pos = {0, 0};
int current_grid[N][N];  // -1 if empty
vector<int> stack_cards;

void move_to(Pos target) {
    while (curr_pos.r < target.r) {
        ops += 'D';
        curr_pos.r++;
    }
    while (curr_pos.r > target.r) {
        ops += 'U';
        curr_pos.r--;
    }
    while (curr_pos.c < target.c) {
        ops += 'R';
        curr_pos.c++;
    }
    while (curr_pos.c > target.c) {
        ops += 'L';
        curr_pos.c--;
    }
}

void pick() {
    ops += 'Z';
    if (current_grid[curr_pos.r][curr_pos.c] != -1) {
        stack_cards.push_back(current_grid[curr_pos.r][curr_pos.c]);
        current_grid[curr_pos.r][curr_pos.c] = -1;

        if (stack_cards.size() >= 2) {
            int sz = stack_cards.size();
            if (stack_cards[sz - 1] == stack_cards[sz - 2]) {
                stack_cards.pop_back();
                stack_cards.pop_back();
            }
        }
    }
}

void place() {
    ops += 'X';
    if (!stack_cards.empty() && current_grid[curr_pos.r][curr_pos.c] == -1) {
        current_grid[curr_pos.r][curr_pos.c] = stack_cards.back();
        stack_cards.pop_back();
    }
}

// Random
struct Xorshift {
    unsigned int x = 123456789;
    unsigned int next() {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return x;
    }
    int nextInt(int max) {
        if (max <= 0) return 0;
        return next() % max;
    }
    double nextDouble() {
        return next() / 4294967296.0;
    }
} rng;

int main() {
    // Setup
    auto start_time = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_in;
    if (!(cin >> n_in)) return 0;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> initial_grid[r][c];
            current_grid[r][c] = initial_grid[r][c];
        }
    }

    for (int i = 0; i < NUM_BLOCKS; ++i) blocks[i].init(i);

    // Phase 1: Collect All
    int collected_count = 0;
    int total_cards = N * N;
    bool visited[N][N] = {false};
    
    // Heuristic parameter: How much extra distance we are willing to travel
    // to match a card immediately and save Phase 2 costs.
    // Phase 2 cost is roughly moving to a block + moving inside block.
    const int MATCH_BONUS = 15; 
    
    while(collected_count < total_cards) {
        // 1. Find nearest card
        int dist_nearest = 1e9;
        Pos target_nearest = {-1, -1};
        
        for(int r=0; r<N; ++r) {
            for(int c=0; c<N; ++c) {
                if (!visited[r][c]) {
                    int d = curr_pos.dist({r, c});
                    if (d < dist_nearest) {
                        dist_nearest = d;
                        target_nearest = {r, c};
                    }
                }
            }
        }
        
        // 2. Find matching card (if stack not empty)
        int dist_match = 1e9;
        Pos target_match = {-1, -1};
        bool can_match = false;
        
        if (!stack_cards.empty()) {
            int val_top = stack_cards.back();
            // Find the other card with same value
            for(int r=0; r<N; ++r) {
                for(int c=0; c<N; ++c) {
                    if (!visited[r][c] && initial_grid[r][c] == val_top) {
                        dist_match = curr_pos.dist({r, c});
                        target_match = {r, c};
                        can_match = true;
                        goto found_match_search; // Optimization: only 1 such card exists
                    }
                }
            }
        }
        found_match_search:;
        
        // 3. Decide
        Pos final_target = target_nearest;
        
        if (can_match) {
            // If matching is reasonably close, prefer it.
            // Logic: dist_match <= dist_nearest + MATCH_BONUS
            if (dist_match <= dist_nearest + MATCH_BONUS) {
                final_target = target_match;
            }
        }
        
        if (final_target.r != -1) {
            move_to(final_target);
            pick();
            visited[final_target.r][final_target.c] = true;
            collected_count++;
        } else {
            break;
        }
    }
    
    // stack_cards has the remaining cards
    vector<int> cards_to_place = stack_cards;
    reverse(cards_to_place.begin(), cards_to_place.end()); // Order of appearance from stack
    
    if (cards_to_place.empty()) {
        for (char c : ops) cout << c << "\n";
        return 0;
    }
    
    // Phase 2: Assign blocks
    map<int, int> card_counts;
    for(int v : cards_to_place) card_counts[v]++;
    vector<int> unique_cards;
    for(auto const& [val, count] : card_counts) if(count == 2) unique_cards.push_back(val);
    
    map<int, int> assignment;
    vector<int> block_load(NUM_BLOCKS, 0);
    
    // Initial random assignment
    int b_idx = 0;
    int limit_per_block = max(1, MAX_BLOCK_CAPACITY - 1); // Leave 1 spot for maneuvering

    for(int val : unique_cards) {
        int safety = 0;
        while(block_load[b_idx] >= limit_per_block) {
            b_idx = (b_idx + 1) % NUM_BLOCKS;
            safety++;
            if(safety > NUM_BLOCKS * 2) break; 
        }
        assignment[val] = b_idx;
        block_load[b_idx]++;
        b_idx = (b_idx + 1) % NUM_BLOCKS;
    }
    
    // Annealing
    Pos sim_curr = curr_pos; // Starting pos for phase 2
    
    auto calc_cost = [&](const map<int, int>& assign) {
        double cost = 0;
        Pos c = sim_curr;
        for(int val : cards_to_place) {
            int bid = assign.at(val);
            Pos t = blocks[bid].center;
            cost += c.dist(t);
            c = t;
        }
        return cost;
    };
    
    double best_score = calc_cost(assignment);
    map<int, int> best_assignment = assignment;
    
    int iter = 0;
    
    while(true) {
        iter++;
        if ((iter & 0xFF) == 0) {
            auto now = chrono::steady_clock::now();
            if (chrono::duration<double>(now - start_time).count() > TIME_LIMIT * 0.8) break;
        }
        
        int type = rng.nextInt(2);
        if (unique_cards.empty()) break; 
        int u1 = unique_cards[rng.nextInt(unique_cards.size())];
        int b1 = assignment[u1];
        
        if (type == 0) { // Move
            int b2 = rng.nextInt(NUM_BLOCKS);
            if (b1 == b2 || block_load[b2] >= limit_per_block) continue;
            
            assignment[u1] = b2;
            block_load[b1]--; block_load[b2]++;
            
            double new_score = calc_cost(assignment);
            if (new_score < best_score) { // Simple greedy descent
                best_score = new_score;
                best_assignment = assignment;
            } else { // Revert
                assignment[u1] = b1;
                block_load[b1]++; block_load[b2]--;
            }
        } else { // Swap
            int u2 = unique_cards[rng.nextInt(unique_cards.size())];
            int b2 = assignment[u2];
            if (b1 == b2) continue;
            
            assignment[u1] = b2; assignment[u2] = b1;
            
            double new_score = calc_cost(assignment);
            if (new_score < best_score) {
                best_score = new_score;
                best_assignment = assignment;
            } else {
                assignment[u1] = b1; assignment[u2] = b2;
            }
        }
    }
    
    assignment = best_assignment;
    
    // Execute Placement
    struct BlockState {
        bool occupied[BLOCK_H][BLOCK_W] = {false};
        map<int, Pos> waiting;
        
        // Find empty spot closest to current position 'from'
        Pos find_best_empty(Pos block_topleft, Pos from) {
            int best_d = 1e9;
            Pos best_p = {-1, -1};
            
            for(int r=0; r<BLOCK_H; ++r) {
                for(int c=0; c<BLOCK_W; ++c) {
                    if (!occupied[r][c]) {
                        Pos abs_p = {block_topleft.r + r, block_topleft.c + c};
                        int d = abs(abs_p.r - from.r) + abs(abs_p.c - from.c);
                        if (d < best_d) {
                            best_d = d;
                            best_p = {r, c};
                        }
                    }
                }
            }
            return best_p;
        }
    };
    
    vector<BlockState> bstates(NUM_BLOCKS);
    
    for(int val : cards_to_place) {
        int bid = assignment[val];
        
        if (bstates[bid].waiting.count(val)) {
            // 2nd card: Go to the first card and pick it up
            Pos local = bstates[bid].waiting[val];
            Pos target = {blocks[bid].r_min + local.r, blocks[bid].c_min + local.c};
            
            move_to(target);
            pick(); 
            
            // Free the spot
            bstates[bid].occupied[local.r][local.c] = false;
            bstates[bid].waiting.erase(val);
        } else {
            // 1st card: Place it in the BEST empty spot
            Pos block_tl = {blocks[bid].r_min, blocks[bid].c_min};
            Pos local = bstates[bid].find_best_empty(block_tl, curr_pos);
            
            if (local.r == -1) {
                continue; 
            }
            Pos target = {blocks[bid].r_min + local.r, blocks[bid].c_min + local.c};
            
            move_to(target);
            place();
            
            // Mark as occupied
            bstates[bid].occupied[local.r][local.c] = true;
            bstates[bid].waiting[val] = local;
        }
    }

    for (char c : ops) cout << c << "\n";

    return 0;
}