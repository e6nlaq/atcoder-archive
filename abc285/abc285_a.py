
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


def inpi():
    n = map(int, input().split())
    return n


def inps():
    s = input().split()
    return s


def main():
    # Write code
    a, b = inpi()

    if b == a*2 or b == a*2+1:
        print("Yes")
    else:
        print("No")


main()
