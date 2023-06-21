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

    ans: int = 0
    for _ in range(H):
        S = input()
        ans += S.count("#")

    print(ans)


if __name__ == "__main__":
    main()
