
def main():
    N = int(input())
    A = list(input().split(" "))

    dat = {}
    ans = 0

    for i in range(N):
        dat.setdefault(A[i], 0)

        dat[A[i]] += 1
        if dat[A[i]] == 2:
            ans += 1
            dat[A[i]] = 0

    print(ans)


main()
