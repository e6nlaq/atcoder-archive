ans=0;
N=int(input())
S=input()
T=input()

for i in range(N):
    if S[i]!=T[i]:
        ans+=1

print(ans)