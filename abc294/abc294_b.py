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
    H, W = map(int, input().split(" "))
    A = [list(map(int, input().split(" "))) for i in range(H)]

    for i in range(H):
        ans = ""
        for j in range(W):
            if A[i][j] == 0:
                ans += "."
            else:
                ans += chr(0x40 + A[i][j])

        print(ans)


if __name__ == "__main__":
    main()
