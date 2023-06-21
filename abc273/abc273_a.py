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


def f(x: int):
    if x == 0:
        return 1
    else:
        return x * f(x - 1)


def main():
    N = int(input())
    print(f(N))


if __name__ == "__main__":
    main()
