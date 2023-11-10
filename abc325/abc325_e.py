# ------------------------------------------------------------
#
#
# 	   Welcome to my program!
# 	   DON'T HACK PLEASE!!!!!!!!
#
# 	縲縲竏ｧ・ｿ竏ｧ        AtCoder / Codeforces
# 	縲 ( 縲・･ﾏ会ｽ･)
# 	・ｿ(__縺､/・｣・｣・｣ /  MIT License
# 	縲縲・ｼ/縲縲縲縲 /  Python 3.10.12
# 	縲縲縲縲・｣・｣・｣・｣・｣
# 		   Let's write Code!
#
#
# ------------------------------------------------------------

import numpy as np
from collections import *
import math


def main():
    N, A, B, C = map(int, input().split(" "))
    D: list[list[int]] = [[] * (N + 1) for i in range(N + 1)]
    for i in range(1, N + 1):
        D[i] = [0] + list(map(int, input().split(" ")))

    dp: list[list[int]] = [[10**12] * (N + 1) for i in range(2)]
    # print(D, dp)
    dp[0][1] = 0
    dp[1][1] = 0

    q = deque([1])

    while len(q) > 0:
        i = q[0]
        q.popleft()

        for j in range(1, N + 1):
            if dp[0][j] > dp[0][i] + (D[i][j] * A):
                dp[0][j] = dp[0][i] + (D[i][j] * A)
                q.append(j)

            if dp[1][j] > min(
                dp[0][i] + (D[i][j] * B + C), dp[1][i] + (D[i][j] * B + C)
            ):
                dp[1][j] = min(
                    dp[0][i] + (D[i][j] * B + C), dp[1][i] + (D[i][j] * B + C)
                )
                q.append(j)

    # print(dp)
    print(min(dp[0][N], dp[1][N]))


if __name__ == "__main__":
    main()
