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
    S: str = input()

    ans: int = 0
    for i in range(len(S)):
        if S[i] == "v":
            ans += 1
        else:
            ans += 2

    print(ans)


if __name__ == "__main__":
    main()
