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

def main():
    N,M,K=map(int,input().split())
    ok=0
    ng=10**30
    while ng-ok>1:
        mid=(ok+ng)//2
        no=mid//N+mid//M
        no-=2*(mid//math.lcm(N,M))
        if no<K:
            ok=mid
        else:
            ng=mid

    print(ng)


    

if __name__ == '__main__':
    main()
