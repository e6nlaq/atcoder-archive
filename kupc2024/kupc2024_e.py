A=list(map(int,input().split()))
B=list(map(int,input().split()))
ans=0
for x in A:
    for y in B:
        ans+=x*y
        
print(ans)