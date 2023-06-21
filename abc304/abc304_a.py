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
    S = []
    mn = 99999999999
    ai = -1
    for i in range(N):
        s = input().split(" ")
        S.append(s[0])
        if mn > int(s[1]):
            mn = int(s[1])
            ai = i

    for i in range(ai, ai + N):
        i %= N
        print(S[i])


if __name__ == "__main__":
    main()
