
def main():
    N, X = map(int, input().split(" "))
    A = set(input().split(" "))

    for B in A:
        if str(int(B)+X) in A:
            print("Yes")
            exit(0)

    print("No")


main()
