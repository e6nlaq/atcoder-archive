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

def conv(n:str,base:int)->int:
    ans=0
    for i,c in enumerate(n):
        x=int(c)
        ans+=x*pow(base,len(n)-i-1)
    return ans

def main():
    X=input()
    M=int(input())
    d=int(max(X))+1

    if int(X,d)>M:
        print(0)
        return

    if len(X)==1:
        print(1)
        return


    ok=d
    ng=M+1
    while ng-ok>1:
        m=(ng+ok)//2
        if conv(X,m)<=M:
            ok=m
        else:
            ng=m
    print(ok,ng,file=sys.stderr)
    print(ok-d+1)


if __name__ == '__main__':
    main()
