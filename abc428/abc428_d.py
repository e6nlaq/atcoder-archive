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
import sys

def solve(n):
    return int(math.isqrt(n)+ 1e-17)

def main():
    T=int(input())
    for _ in range(T):
        C,D=map(int,input().split())
        cs=str(C)
        r=int(cs+str(C+D))
        l=cs+cs
        ans=0

        for n in range(1,12):
            L=int(cs+str(max(C,10**(n-1))))
            R=int(cs+str(min(int("9"*n),C+D)))
            
            if R<L:
                continue


            ad=solve(R)-solve(L-1)
            ans+=ad
            # print(L,R,ad,file=sys.stderr)
        
        print(ans)






if __name__ == '__main__':
    main()
