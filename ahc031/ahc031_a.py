# read input
W, D, N = map(int, input().split())
a = []
for d in range(D):
    a.append(list(map(int, input().split())))

# determine rectangles
rect = [[] for _ in range(D)]
for d in range(D):
    for k in range(N):
        rect[d].append((k, 0, k + 1, W))

# output
for d in range(D):
    for k in range(N):
        i0, j0, i1, j1 = rect[d][k]
        print(i0, j0, i1, j1)
