T=int(input())

# 引用: https://procon.fun/code/circle-overlap/

for _ in range(T):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    
    isOverlap = True
    d = (x1 - x2)**2 + (y1 - y2)**2  #ルートはとっていませんので、以下の計算も2乗した状態で計算していきます
    if d > (r1 + r2)**2 or d < (r1 - r2)**2:
        isOverlap = False
    
    print("Yes" if isOverlap else "No")
    
