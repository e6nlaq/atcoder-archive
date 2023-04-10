
def main():
    H, W = map(int, input().split(' '))
    S = []

    for i in range(H):
        S.append(input())

    for i in range(H):
        for j in range(W-1):
            if S[i][j] == 'T' and S[i][j+1] == 'T':
                S[i] = S[i][:j]+'P'+S[i][j+1:]
                S[i] = S[i][:j+1]+'C'+S[i][j+2:]

    for i in range(H):
        print(S[i])


main()
