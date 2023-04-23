def main():
    N = int(input())
    S = input()

    flag = False
    for x in S:
        if x == "|":
            flag = not flag
        elif x == "*":
            if flag:
                print("in")
            else:
                print("out")
            return


main()
