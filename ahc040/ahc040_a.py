import random

def query(prdb):
    print(len(prdb))
    for p, r, d, b in prdb:
        print(p, r, d, b)
    W, H = map(int, input().split())
    return W, H

N, T, sigma = map(int, input().split())
wh = [tuple(map(int, input().split())) for _ in range(N)]

rng = random.Random(1234)

for _ in range(T):
    prdb = []
    for i in range(N):
        prdb.append((
            i,
            rng.randint(0, 1),
            ['U', 'L'][rng.randint(0, 1)],
            rng.randint(-1, i - 1),
        ))
    query(prdb)
