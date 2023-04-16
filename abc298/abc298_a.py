def main():
    N = int(input())
    S = input()

    if S.count("o") >= 1 and S.count("x") == 0:
        print("Yes")
    else:
        print("No")


main()
