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
    p: list = [int(input()) for i in range(N)]
    p.sort(reverse=True)
    ans = 0
    for i in range(N):
        if i == 0:
            ans += p[i] // 2
        else:
            ans += p[i]

    print(ans)


if __name__ == "__main__":
    main()
