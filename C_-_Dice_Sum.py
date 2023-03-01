MOD = 998244353

def binpow(a, b, mod = MOD):
    if (b == 0):
        return 1
    if (b == 1):
        return a % mod
    if (b % 2 == 0):
        return binpow(a * a % mod, b // 2, mod)
    else:
        return a * binpow(a * a % mod, b // 2, mod) % mod

def comb(n, k, mod = MOD):
    if (n < k):
        return 0
    if (n == k):
        return 1
    ans = 1
    for i in range(1, k + 1):
        ans = (ans * (n - i + 1) % mod * binpow(i, mod - 2, mod) % mod)
    return ans

n,m,k = map(int, input().split())
ans1 = 0
for i in range(k - n + 1):
    ans1 += comb(n + i - 1, n - 1)