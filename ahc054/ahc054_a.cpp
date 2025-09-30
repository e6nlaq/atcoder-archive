#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <random>
#include <stack> // For DFS
#include <tuple> // For stack elements

using namespace std;

int N;
pair<int, int> flower_pos;
pair<int, int> start_pos;

// 4方向の移動 (1マス移動)
int dr[] = {-1, 1, 0, 0}; // 0:Up, 1:Down, 2:Left, 3:Right
int dc[] = {0, 0, -1, 1};

// 4方向の移動 (2マス移動、穴掘り用)
int dr_dig[] = {-2, 2, 0, 0};
int dc_dig[] = {0, 0, -2, 2};

// (start) から (goal) まで到達可能かチェックする関数 (BFS)
bool is_connected(const vector<string>& board, pair<int, int> start, pair<int, int> goal) {
    if (board[start.first][start.second] == '#' || board[goal.first][goal.second] == '#') {
        return false;
    }
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == goal) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N &&
                board[nr][nc] == '.' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // --- 初期入力 ---
    cin >> N >> flower_pos.first >> flower_pos.second;
    vector<string> initial_board(N);
    for (int i = 0; i < N; ++i) {
        cin >> initial_board[i];
    }

    start_pos = {0, N / 2};

    // --- 迷路生成 (穴掘り法) --- 
    // generated_mazeは最終的に冒険者に見せる迷路の状態
    // initial_boardで元々壁だった場所はgenerated_mazeでも壁のままにする
    vector<string> generated_maze = initial_board; 
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(generated_maze[i][j] == '.') {
                generated_maze[i][j] = '#'; // 元々空きマスだった場所を一旦全て壁にする
            }
        }
    }

    vector<vector<bool>> visited_dfs(N, vector<bool>(N, false));
    stack<tuple<int, int, int>> s; // {row, col, previous_direction_index}
    random_device rd;
    mt19937 g(rd());

    // 穴掘りDFSの開始
    s.push({start_pos.first, start_pos.second, -1}); // -1 for no previous direction
    visited_dfs[start_pos.first][start_pos.second] = true;
    generated_maze[start_pos.first][start_pos.second] = '.';

    while (!s.empty()) {
        auto [r, c, prev_dir_idx] = s.top();
        s.pop(); // Pop immediately, will push back if neighbors found

        vector<int> possible_next_dirs; // Store indices of valid directions
        for (int i = 0; i < 4; ++i) {
            // 同じ方向への連続移動を避ける
            if (prev_dir_idx != -1 && i == (prev_dir_idx ^ 1)) { // prev_dir_idxの逆方向
                continue;
            }

            int nr = r + dr_dig[i];
            int nc = c + dc_dig[i];

            // 2マス先の隣接セルが範囲内かつ未訪問、かつその間のセルが元のボードで壁ではない
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited_dfs[nr][nc]) {
                int wall_r = r + dr[i]; // 1マス先の壁
                int wall_c = c + dc[i]; // 1マス先の壁
                // 元々空きマスだった場所のみ掘れる
                if (initial_board[wall_r][wall_c] == '.' && initial_board[nr][nc] == '.') {
                    possible_next_dirs.push_back(i);
                }
            }
        }

        if (!possible_next_dirs.empty()) {
            s.push({r, c, prev_dir_idx}); // 戻るために現在のセルをスタックに戻す
            shuffle(possible_next_dirs.begin(), possible_next_dirs.end(), g); // ランダムな隣接方向を選択

            int chosen_dir_idx = possible_next_dirs[0];
            pair<int, int> next = {r + dr_dig[chosen_dir_idx], c + dc_dig[chosen_dir_idx]};

            // 間の壁を掘る
            int wall_r = r + dr[chosen_dir_idx];
            int wall_c = c + dc[chosen_dir_idx];

            generated_maze[wall_r][wall_c] = '.';
            generated_maze[next.first][next.second] = '.';
            visited_dfs[next.first][next.second] = true;
            s.push({next.first, next.second, chosen_dir_idx}); // 次のセルと、そこに至った方向をスタックにプッシュ
        }
    }

    // 花のマスを確実に開ける
    generated_maze[flower_pos.first][flower_pos.second] = '.';

    // 花のマスから、既に掘られた迷路に接続する (BFSで最短経路を掘る)
    // is_connected関数はstart_posからflower_posへの経路があるかチェックするが、
    // ここではgenerated_maze内でflower_posがstart_posから到達可能なパスに接続されているかを確認する
    if (!is_connected(generated_maze, start_pos, flower_pos)) {
        queue<pair<int, int>> q_connect;
        q_connect.push(flower_pos);
        vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
        vector<vector<bool>> visited_connect(N, vector<bool>(N, false));
        visited_connect[flower_pos.first][flower_pos.second] = true;

        pair<int, int> connected_to = {-1, -1};

        while (!q_connect.empty()) {
            pair<int, int> curr = q_connect.front();
            q_connect.pop();

            // 既に掘られた迷路のパスに到達したら終了
            if (generated_maze[curr.first][curr.second] == '.' && curr != flower_pos) {
                connected_to = curr;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];

                // 範囲内、未訪問、かつinitial_boardで元々空きマスだった場所のみ進める
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited_connect[nr][nc] && initial_board[nr][nc] == '.') {
                    visited_connect[nr][nc] = true;
                    parent[nr][nc] = curr;
                    q_connect.push({nr, nc});
                }
            }
        }

        // 経路を遡って掘る
        if (connected_to.first != -1) {
            pair<int, int> curr = connected_to;
            while (curr.first != -1 && curr.second != -1 && curr != flower_pos) {
                generated_maze[curr.first][curr.second] = '.';
                curr = parent[curr.first][curr.second];
            }
        }
    }


    // --- 最初のターン: 新しい木を出力 --- 
    vector<pair<int, int>> new_trees;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 元々空きマスだったが、生成された迷路では壁になったマスを新しい木とする
            if (initial_board[i][j] == '.' && generated_maze[i][j] == '#') {
                new_trees.push_back({i, j});
            }
        }
    }

    // 冒険者の情報を読み飛ばす (最初のターン)
    int pi, pj, n;
    cin >> pi >> pj >> n;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
    }

    // 新しい木の情報を出力
    cout << new_trees.size();
    for (const auto& p : new_trees) {
        cout << " " << p.first << " " << p.second;
    }
    cout << endl;

    // --- 2ターン目以降 ---
    while (true) {
        cin >> pi >> pj;
        if (pi == flower_pos.first && pj == flower_pos.second) {
            break; // 冒険者がゴール
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
        }

        // 何も配置しない
        cout << 0 << endl;
    }

    return 0;
}
