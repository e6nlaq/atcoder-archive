A, B = map(int, input().split(" "))
ans = 0

while A != B:
    if B > A:
        A, B = B, A

    ans += int(A / (B + 1))
    A -= B * int(A / (B + 1))

print(ans)
