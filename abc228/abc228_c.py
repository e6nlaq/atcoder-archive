# To 1998.

import bisect
n,k=map(int,input().split())
score=[]
for i in range(n):
    a,b,c=map(int,input().split())
    score.append(a+b+c)
df=score.copy()
score.sort()
for i in range(n):
    w=df[i]+300
    
    # ただし、4 日目の試験後の生徒の順位は、その生徒よりも 4 日間の合計点が高い生徒の人数に ""1 を加えた値"" として定めます。
    print("Yes" if k>=n-bisect.bisect_right(score,w)+1 else"No")
    