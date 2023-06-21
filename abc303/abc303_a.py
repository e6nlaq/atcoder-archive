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


def solve(s: str):
    ret = []
    for i in range(len(s)):
        if s[i] == "1":
            ret.append("l")
        elif s[i] == "0":
            ret.append("o")
        else:
            ret.append(s[i])

    return "".join(ret)


def main():
    N = int(input())
    S = input()
    T = input()

    if solve(S) == solve(T):
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
