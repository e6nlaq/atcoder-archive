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
    s = list(input())

    for i in range(len(s)):
        if s[i] == "0":
            s[i] = "1"
        else:
            s[i] = "0"

    print("".join(s))


if __name__ == "__main__":
    main()
