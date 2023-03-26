
def manhat(r1, r2, c1, c2):
    return abs(r1 - r2)+abs(c1 - c2)


def main():
    R, C = map(int, input().split(" "))
    B = []

    for _ in range(R):
        B.append(list(input()))

    for i in range(R):
        for j in range(C):
            if B[i][j].isdigit():
                for k in range(R):
                    for l in range(C):
                        if B[k][l] == "#" and manhat(i+1, k+1, j+1, l+1) <= int(B[i][j]):
                            B[k][l] = "."
                B[i][j] = "."

    for i in range(R):
        print("".join(B[i]))


main()
