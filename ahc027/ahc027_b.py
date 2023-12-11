import sys
sys.setrecursionlimit(1000000)
N = int(input())
h = [input() for _ in range(N-1)]
v = [input() for _ in range(N)]
d = [list(map(int, input().split())) for _ in range(N)]
visited = [[False for _ in range(N)] for _ in range(N)]
DIJ = [(0, 1), (1, 0), (0, -1), (-1, 0)]
DIR = "RDLU"
def dfs(i, j):
    visited[i][j] = True
    for dir in range(4):
        di, dj = DIJ[dir]
        i2 = i + di
        j2 = j + dj
        if 0 <= i2 < N and 0 <= j2 < N and not visited[i2][j2]:
            if di == 0 and v[i][min(j, j2)] == '0' or dj == 0 and h[min(i, i2)][j] == '0':
                print(DIR[dir], end='')
                dfs(i2, j2)
                print(DIR[(dir + 2) % 4], end='')
dfs(0, 0)
print()
