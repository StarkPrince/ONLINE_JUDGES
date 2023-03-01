# recursion dp
def helper(coins, amount, d):
    if amount == 0:
        return 0
    if amount < 0:
        return -1
    mn = 10**9
    if d[amount] != -2:
        return d[amount]
    for coin in coins:
        k = helper(coins, amount-coin, d)
        if k != -1:
            mn = min(mn, 1+k)
    if mn != 10**9:
        d[amount] = mn
    else:
        d[amount] = -1
    return d[amount]

# iteration dp


d = [-2]*1000005
n, amount = [int(x) for x in input().split()]
coins = [int(x) for x in input().split()]
print(helper(coins, amount, d))
