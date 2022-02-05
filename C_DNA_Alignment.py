def binpow(a, b, mod):
    a %= mod
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res


n = int(input())
s = input()
l = len(set(list(s)))
print(binpow(l, n, 10 ** 9 + 7))
