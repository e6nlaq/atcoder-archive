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
    S = input()

    t = S.count("T")
    a = S.count("A")

    if t > a:
        print("T")
    elif t < a:
        print("A")
    else:
        if S[N - 1] == "T":
            print("A")
        else:
            print("T")


if __name__ == "__main__":
    main()
