def maxValueOfCoins(piles, k):
    for p in piles:
        for i in range(1, len(p)):
            p[i] += p[i-1]
    print(piles)

    def recur(i, r):
        if i == len(piles) or r == 0:
            return 0
            # first case is when you add 0 elements to your wallet
            # second case is when you add j + 1 elements to your wallet.
        return max([recur(i + 1, r)] +
                   [recur(i + 1, r - (j+1)) + piles[i][j] for j in range(min(r, len(piles[i])))])

    return recur(0, k)


n, k = [int(x) for x in input().split()]
piles = []
for i in range(n):
    piles.append([int(x) for x in input().split()])
print(maxValueOfCoins(piles, k))
