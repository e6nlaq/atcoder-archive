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
    p, q = map(str, input().split(" "))
    dic = {"A": 0, "B": 3, "C": 4, "D": 8, "E": 9, "F": 14, "G": 23}

    print(abs(dic[p] - dic[q]))


if __name__ == "__main__":
    main()
