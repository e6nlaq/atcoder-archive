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
    S = list(input())
    for i in range(int(len(S) / 2)):
        S[2 * i], S[2 * i + 1] = S[2 * i + 1], S[2 * i]

    print("".join(S))


if __name__ == "__main__":
    main()
