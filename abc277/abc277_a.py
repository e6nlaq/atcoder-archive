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
    N, X = map(int, input().split(" "))
    P = list(map(int, input().split(" ")))

    print(P.index(X) + 1)


if __name__ == "__main__":
    main()
