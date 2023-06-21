"""


       Welcome to my program!

    　　∧＿∧        @x__0
    　 ( 　･ω･)      
    ＿(__つ/￣￣￣ /  MIT License
    　　＼/　　　　 /  Python 3.10.6
    　　　　￣￣￣￣￣
           Let's write Code!


"""

import numpy
import collections
import math


def main():
    N = int(input())
    A = list(map(int, input().split(" ")))

    ans = []
    for i in range(N):
        if A[i] % 2 == 0:
            ans.append(str(A[i]))

    print(" ".join(ans))


if __name__ == "__main__":
    main()
