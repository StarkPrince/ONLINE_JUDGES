maxN = 100005
MOD = 10**9 + 7

n, m = map(int, input().split())
fact = [0] * maxN
inv = [0] * maxN


def inverse(x):
    res = 1
    expo = MOD-2
    while expo > 0:
        if expo & 1:
            res = (res * x) % MOD
        x = (x * x) % MOD
        expo >>= 1
    return res


def init():
    fact[0] = inv[0] = 1
    for i in range(1, maxN):
        fact[i] = (i * fact[i-1]) % MOD
        inv[i] = inverse(fact[i])


def choose(n, k):
    if n < k:
        return 0
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD


init()
print(choose(n+m-1, n-1))
