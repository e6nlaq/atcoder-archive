
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
    N, K = map(int, input().split())

    A = list(map(int, input().split()))

    for _ in range(K):
        A.pop(0)
        A.append(0)

    print(*A)


main()
