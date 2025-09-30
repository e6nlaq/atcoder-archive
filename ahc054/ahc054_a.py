N, ti, tj = map(int, input().split())
b = [input() for _ in range(N)]
revealed = [[False] * N for _ in range(N)]
while True:
    pi, pj = map(int, input().split())
    parts = input().split()
    n = int(parts[0])
    xy = list(map(int, parts[1:]))
    for k in range(n):
        x = xy[2 * k]
        y = xy[2 * k + 1]
        revealed[x][y] = True
    if pi == ti and pj == tj:
        break
    print(0, flush=True)
