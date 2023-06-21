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
    S = [input() for i in range(N)]

    print("Yes" if S.count("For") > N / 2 else "No")


if __name__ == "__main__":
    main()
