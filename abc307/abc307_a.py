"""



       Welcome to my program!

    　　∧＿∧        @x__0
    　 ( 　･ω･)      
    ＿(__つ/￣￣￣ /  MIT License
    　　＼/　　　　 /  Python 3.10.6
    　　　　￣￣￣￣￣
           Let's write Code!


"""

import numpy as np
import collections
import math


def main():
    N = int(input())
    A = list(map(int, input().split(" ")))
    B = []

    for i in range(N):
        sum = 0
        for j in range(7):
            sum += A[i * 7 + j]

        B.append(str(sum))

    print(" ".join(B))


if __name__ == "__main__":
    main()
