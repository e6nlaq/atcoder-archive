
def main():

    WORDS = ["and", "not", "that", "the", "you"]

    N = int(input())
    W = list(input().split(' '))

    for i in range(N):
        if W[i] in WORDS:
            print("Yes")
            exit()

    print("No")


main()
