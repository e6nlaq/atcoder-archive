
# Hello, Python AtCoder!
# Copyright (c) 2023- x__0

import bisect
import collections
import copy
import heapq
import itertools
import math
# import numpy
import string
import sys


def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


def main():
    N = int(input())
    S = []

    for i in range(N):
        s = input()
        S.append(s)

    S.reverse()

    for s in S:
        print(s)


main()
