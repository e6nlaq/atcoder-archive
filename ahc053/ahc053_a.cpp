#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <random>

// Function to solve the problem
void solve() {
    // Phase 1: Determine and print A_i
    long long N, M, L, U;
    std::cin >> N >> M >> L >> U;

    std::vector<long long> A(N);
    int idx = 0;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Adjustment Cards (450) with dynamic max value
    long long max_val = U - L;
    int num_to_gen[] = {225, 113, 56, 28, 14, 7, 4, 2, 1};
    for (int count : num_to_gen) {
        if (max_val < 1) max_val = 1;
        std::uniform_int_distribution<long long> dist(1, max_val);
        for (int i = 0; i < count; ++i) {
            if (idx < N) {  // Safeguard
                A[idx++] = dist(gen);
            }
        }
        max_val /= 128;
    }

    // Base Cards (50)
    for (int i = 0; i < 50; ++i) {
        if (idx < N) {  // Safeguard
            A[idx++] = L;
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << A[i] << (i == N - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Phase 2: Read B_j and determine X_i
    std::vector<long long> B(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
    }

    std::vector<std::pair<long long, int>> A_indexed(N);
    for (int i = 0; i < N; ++i) {
        A_indexed[i] = {A[i], i};
    }
    std::sort(A_indexed.rbegin(), A_indexed.rend());

    std::vector<long long> S(M, 0);
    std::vector<int> X(N, 0);
    std::vector<bool> used(N, false);
    std::vector<bool> mountain_full(M, false);

    // Mountain-filling Phase 1: Mountain-centric, non-exceeding
    while (true) {
        int best_j = -1;
        long long max_rem = -1;
        for (int j = 0; j < M; ++j) {
            if (mountain_full[j]) continue;
            if (B[j] - S[j] > max_rem) {
                max_rem = B[j] - S[j];
                best_j = j;
            }
        }

        if (best_j == -1) break;

        int card_to_add_idx = -1;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && S[best_j] + A_indexed[i].first <= B[best_j]) {
                card_to_add_idx = i;
                break;
            }
        }

        if (card_to_add_idx != -1) {
            int original_A_index = A_indexed[card_to_add_idx].second;
            long long val = A_indexed[card_to_add_idx].first;
            X[original_A_index] = best_j + 1;
            S[best_j] += val;
            used[card_to_add_idx] = true;
        } else {
            mountain_full[best_j] = true;
        }
    }

    // Mountain-filling Phase 2: Final adjustment, exceeding allowed
    while (true) {
        int best_card_idx = -1;
        int best_mountain_idx = -1;
        long double max_improvement = 1e-9;

        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (used[i]) continue;
                long double current_error = std::abs((long double)S[j] - B[j]);
                long double new_error = std::abs((long double)S[j] + A_indexed[i].first - B[j]);
                long double improvement = current_error - new_error;
                if (improvement > max_improvement) {
                    max_improvement = improvement;
                    best_card_idx = i;
                    best_mountain_idx = j;
                }
            }
        }

        if (best_card_idx != -1) {
            int original_A_index = A_indexed[best_card_idx].second;
            long long val = A_indexed[best_card_idx].first;
            X[original_A_index] = best_mountain_idx + 1;
            S[best_mountain_idx] += val;
            used[best_card_idx] = true;
        } else {
            break;
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << X[i] << (i == N - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}