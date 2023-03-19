#
# ?Problem: https://atcoder.jp/contests/abc292/tasks/abc292_b
# *Solution: we can get the number of players that have a yellow card by subtracting the number of players that have a red card from the number of players that have a yellow card

n, q = [int(x) for x in input().split()]
players = [1 for i in range(n)]
for i in range(q):
    r, p = [int(x) for x in input().split()]
    if r == 1:
        players[p - 1] -= 1
    elif r == 2:
        players[p - 1] -= 2
    else:
        if players[p - 1] <= -1:
            print("Yes")
        else:
            print("No")
