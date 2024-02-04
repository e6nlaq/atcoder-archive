# ------------------------------------------------------------
#
#
# 	   Welcome to my program!
# 	   DON'T HACK PLEASE!!!!!!!!
#
# 	　　∧＿∧        AtCoder / Codeforces
# 	　 ( 　･ω･)
# 	＿(__つ/￣￣￣ /  MIT License
# 	　　＼/　　　　 /  Python 3.10.12
# 	　　　　￣￣￣￣￣
# 		   Let's write Code!
#
#
# ------------------------------------------------------------

import numpy as np
from collections import *
import math
from random import randint


def main():
    N = int(input())
    mod = randint(10**100, 10**110)
    A = [int(input()) % mod for i in range(N)]
    dat = defaultdict(int)
    for x in A:
        dat[x] += 1

    ans = 0
    for i in range(N):
        for j in range(N):
            if dat[(A[i] * A[j]) % mod] != 0:
                ans += dat[(A[i] * A[j]) % mod]

    print(ans)


if __name__ == "__main__":
    main()
