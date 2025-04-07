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

import sys
import numpy as np
import math

def main():
    N=int(input())
    a=1
    ans=0
    while (1<<a)<=N:
        ok=1
        ng=10**10
        while ng-ok>1:
            mid=(ok+ng)//2
            if (1<<a)*mid*mid<=N:
                ok=mid
            else:
                ng=mid


        ans+=ok-(ok//2)-1
        print(a,ok,ng,ans,math.floor(math.log2(ok))+1,file=sys.stderr)
        a+=1

    for i in range(1, 100):
        if 2**i<=N:
            ans+=1

    print(ans)



if __name__ == '__main__':
    main()
