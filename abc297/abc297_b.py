
def main():
    S = input()

    pos1 = S.find('B')
    pos2 = S.rfind('B')

    pos1 %= 2
    pos2 %= 2

    if pos1 == pos2:
        print("No")
        return

    check = False
    for x in S:
        if x == 'R':
            check = not check

        if x == 'K' and not check:
            print("No")
            return

    print("Yes")


main()
