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
    S = input()
    ans: str = "-1"
    for i in range(26):
        tmp = chr(97 + i)
        if S.count(tmp) == 1:
            ans = tmp

    print(ans)


if __name__ == "__main__":
    main()
