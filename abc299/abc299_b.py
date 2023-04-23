def main():
    N, T = map(int, input().split(" "))
    C = list(map(int, input().split(" ")))
    R = list(map(int, input().split(" ")))

    if C.count(T) == 0:
        T = C[0]

    ans = [-1, -1]
    for i in range(N):
        if C[i] == T and R[i] > ans[1]:
            ans[0] = i + 1
            ans[1] = R[i]

    print(ans[0])


main()
