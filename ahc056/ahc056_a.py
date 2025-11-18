# 入力
N, K, T = map(int, input().split())
v = [input().strip() for _ in range(N)]
h = [input().strip() for _ in range(N - 1)]
targets = [tuple(map(int, input().split())) for _ in range(K)]

# 移動可能か判定する関数
DIJ = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
def can_move(i, j, d):
    if d == 'U':
        if i == 0: return False
        return h[i - 1][j] == '0'
    elif d == 'D':
        if i == N - 1: return False
        return h[i][j] == '0'
    elif d == 'L':
        if j == 0: return False
        return v[i][j - 1] == '0'
    elif d == 'R':
        if j == N - 1: return False
        return v[i][j] == '0'
    return False

# --- 戦略 ---
# 内部状態は常に0とする。
# 各マスに異なる初期色を塗り、色の塗り替えは行わず、色で現在位置を表現する。
# 目的地1までのマンハッタン距離が短くなる方向に動し、そのような方向が無いなら停止。
C = N * N
Q = 1
s = [[0] * N for _ in range(N)]
for i in range(N):
     for j in range(N):
          s[i][j] = i * N + j
rules = []
i, j = targets[0] # 現在位置
gi, gj = targets[1] # 最初の目的地
for t in range(T):
    d = 'S'
    if i > gi and can_move(i, j, 'U'):
        d = 'U'
    elif i < gi and can_move(i, j, 'D'):
        d = 'D'
    elif j > gj and can_move(i, j, 'L'):
        d = 'L'
    elif j < gj and can_move(i, j, 'R'):
        d = 'R'
    if d == 'S':
        break
    rules.append((s[i][j], 0, s[i][j], 0, d))
    di, dj = DIJ[d]
    i, j = i + di, j + dj

# 出力
print(C, Q, len(rules))
for r in range(N):
    print(' '.join(map(str, s[r])))
for c, q, A, S, D in rules:
    print(c, q, A, S, D)
