
# Hello, Python AtCoder!
# Copyright (c) 2023- x__0

import bisect
import collections
import copy
import heapq
import itertools
import math
import string
import sys

# region テンプレ


def inpi():
    n = map(int, input().split())
    return n


def inps():
    s = input().split()
    return s


def YesNo(b):
    if b:
        print("Yes")
    else:
        print("No")


def yesno(b):
    if b:
        print("yes")
    else:
        print("no")


def YESNO(b):
    if b:
        print("YES")
    else:
        print("NO")

# endregion


def main():
    # Write code

    T = int(input())

    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        ans = 0

        for i in A:
            if i % 2 == 1:
                ans += 1

        print(ans)

    # main関数実行
main()
