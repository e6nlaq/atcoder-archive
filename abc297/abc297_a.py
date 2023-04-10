
def main():
    N, D = map(int, input().split(" "))
    T = input().split(" ")

    for i in range(N-1):
        if int(T[i+1])-int(T[i]) <= D:
            print(T[i+1])
            exit(0)

    print(-1)


main()
