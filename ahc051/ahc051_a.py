import sys
import math

input = sys.stdin.readline

# 入力読み込み
N, M, K = map(int, input().split())
processor_positions = []
for _ in range(N):
    x, y = map(int, input().split())
    processor_positions.append((x, y))
sorter_positions = []
for _ in range(M):
    x, y = map(int, input().split())
    sorter_positions.append((x, y))
prob = []
for _ in range(K):
    row = list(map(float, input().split()))
    prob.append(row)

# i番の位置にi番の処理装置を設置
proc_assign = ' '.join(str(i) for i in range(N))
# 搬入口 (0,5000) と最も近い設置場所を結ぶ
inlet = (0, 5000)
dist_sq = [((x - inlet[0])**2 + (y - inlet[1])**2, i) for i, (x, y) in enumerate(sorter_positions)]
_, nearest_i = min(dist_sq)
inlet_conn = N + nearest_i

# 0番の分別器を設置し、出口1を一番確率の高いごみ種の処理装置と、出口2を一番確率の低いごみ種の処理装置と結ぶ
first_row = prob[0]
imax = first_row.index(max(first_row))
imin = first_row.index(min(first_row))
sorter_assigns = []
for i in range(M):
    if i == nearest_i:
        sorter_assigns.append(f"0 {imax} {imin}")
    else:
        sorter_assigns.append("-1")

print(proc_assign)
print(inlet_conn)
print("\n".join(sorter_assigns))
