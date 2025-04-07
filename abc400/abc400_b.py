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
    N,M= map(int, input().split())
    x=0
    for i in range(M+1):
        x+=N**i
        if x> 10**9:
            break

    if x>10**9:
        print("inf")
    else:
        print(x)



if __name__ == '__main__':
    main()
