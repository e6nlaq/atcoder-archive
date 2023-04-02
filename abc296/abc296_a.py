
def main():
    N = int(input())
    S = input()

    for i in range(N-1):
        if S[i] == S[i+1]:
            print("No")
            exit(0)

    print("Yes")


main()
