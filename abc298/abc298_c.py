from collections import defaultdict


def main():
    N = int(input())
    Q = int(input())

    card = defaultdict(set)
    box = defaultdict(list)

    for _ in range(Q):
        tmp = list(map(int, input().split(" ")))
        query = tmp[0]
        if query == 1:
            i = tmp[1]
            j = tmp[2]
            card[i].add(j)
            box[j].append(i)
        elif query == 2:
            i = tmp[1]
            ans = box[i]
            ans.sort()
            print(*ans)
        else:
            i = tmp[1]
            ans = list(card[i])
            ans.sort()
            print(*ans)


main()
