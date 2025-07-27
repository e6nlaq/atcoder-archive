# This is not my code. ツ

from itertools import product

N, K, X = map(int, input().split())
S = [input() for _ in range(N)]

candidates = []

for indices in product(range(N), repeat=K):
    s = ''.join(S[i] for i in indices)
    candidates.append(s)

candidates.sort()
print(candidates[X - 1])