import random

random.seed(202410151129)
DX = [0, 1, 0, -1]
DY = [1, 0, -1, 0]
DIR = ['R', 'D', 'L', 'U']

# read input
N, M, V = map(int, input().split())
s = [list(map(int, list(input()))) for _ in range(N)]
t = [list(map(int, list(input()))) for _ in range(N)]

# design the tree
tree = [[0, 1]]
print(len(tree) + 1)
for p, L in tree:
    print(p, L)

# decide the initial position
rx, ry = 0, 0
print(rx, ry)

dir1 = 0 # direction of edge (0, 1)
holding = False # whether holding a takoyaki

for turn in range(10**5):
    S = []
    # random move
    dir = random.randint(0, 3)
    dx, dy = DX[dir], DY[dir]
    if 0 <= rx + dx < N and 0 <= ry + dy < N:
        rx += dx
        ry += dy
        S.append(DIR[dir])
    else:
        S.append('.')
    # random rotate
    rot = random.randint(0, 2)
    if rot == 0:
        S.append('.')
    elif rot == 1:
        S.append('L')
        dir1 = (dir1 + 3) % 4
    else:
        S.append('R')
        dir1 = (dir1 + 1) % 4
    # grab or release takoyaki
    x, y = rx + DX[dir1], ry + DY[dir1]
    change = False
    if 0 <= x and x < N and 0 <= y and y < N:
        if s[x][y] == 1 and t[x][y] == 0 and not holding:
            change = True
            s[x][y] = 0
            holding = True
        elif s[x][y] == 0 and t[x][y] == 1 and holding:
            change = True
            s[x][y] = 1
            holding = False
    S.append('.') # vertex 0 (root) is not a leaf
    if change:
        S.append('P')
    else:
        S.append('.')
    # output the command
    print(''.join(S))
