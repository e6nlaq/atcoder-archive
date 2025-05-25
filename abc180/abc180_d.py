#------------------------------------------------------------
#
#
#	   Welcome to my program!
#	   DON'T HACK PLEASE!!!!!!!!
#
#	　　∧＿∧        AtCoder / Codeforces
#	　 ( 　･ω･)
#	＿(__つ/￣￣￣ /  
#	　　＼/　　　　 /  Python 3.10.12
#	　　　　￣￣￣￣￣
#		   Let's write Code!
#
#
#------------------------------------------------------------

import numpy as np
import math

def main():
    X, Y, A, B = map(int, input().split())
    i=0
    ans=0
    while X*(A**i)<Y:
        now=i
        nokori=Y-X*(A**i)-1
        now+=nokori//B

        if ans<now:
            ans=now
        i+=1
    print(ans)
        


if __name__ == '__main__':
    main()
