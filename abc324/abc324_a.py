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
import collections
import math


def main():
    N = int(input())
    A = list(map(int, input().split()))

    a = A[0]
    flag = True
    for i in range(N):
        if a != A[i]:
            flag = False
            break

    print("Yes" if flag else "No")


if __name__ == "__main__":
    main()
