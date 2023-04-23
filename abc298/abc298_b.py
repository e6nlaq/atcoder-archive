from numpy import rot90


def main():
    N = int(input())
    A = [list(map(int, input().split())) for _ in range(N)]
    B = [list(map(int, input().split())) for _ in range(N)]

    for _ in range(4):
        A = rot90(A)
        ok = True

        for i in range(N):
            for j in range(N):
                if A[i][j] == 1 and B[i][j] == 0:
                    ok = False

        if ok:
            print("Yes")
            return

    print("No")


main()
