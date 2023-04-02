
def main():
    for i in range(8):
        S = input()

        for j in range(8):
            if S[j] == '*':
                print(chr(ord('a')+j)+str(8-i))
                exit(0)


main()
