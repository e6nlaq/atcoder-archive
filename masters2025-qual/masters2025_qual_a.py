N, M = map(int, input().split())
grid = [list(input()) for _ in range(N)]

# 現在位置の取得
pi = 0
pj = 0
for i in range(N):
    for j in range(N):
        if grid[i][j] == 'A':
            pi = i
            pj = j

# 右方向に移動して岩・鉱石を見つけたら穴に運ぶ
for j in range(pj + 1, N):
    if grid[pi][j] == '@' or 'a' <= grid[pi][j] and grid[pi][j] <= 'z':
        print('1 R\n' * (j - pj), end='')
        print('2 L\n' * (j - pj), end='')
    elif 'A' <= grid[pi][j] and grid[pi][j] <= 'Z':
        break

# 下方向に移動して岩・鉱石を見つけたら穴に転がす
for i in range(pi + 1, N):
    if grid[i][pj] == '@' or 'a' <= grid[i][pj] and grid[i][pj] <= 'z':
        print('1 D\n' * (i - pi), end='')
        print('3 U\n', end='')
        pi = i
    elif 'A' <= grid[i][pj] and grid[i][pj] <= 'Z':
        break
