mod = 1000000007


def binpow(a, b):
    a %= mod
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res % mod


d = {}
n = 1
for i in range(int(input())):
    a, b = [int(x) for x in input().split()]
    d[a] = b
    n *= a**b
    n %= 10**9+7
s0 = 1
for i in d.values():
    s0 *= i+1
    s0 %= mod
s1 = 1
for i, j in d.items():
    numerator = (binpow(x[i], k[i]+1)-1+mod) % mod
    denominator = binpow(x[i]-1, mod-2)
    temp = numerator * denominator % mod
    s1 = (s1 * temp) % mod
p1 = 0
if s0 % 2 == 0:
    p1 = binpow(n, s0//2)
else:
    p1 = binpow(n, s0//2)
    p1 *= int(n**(0.5))
    p1 %= mod
print(s0, s1, p1)
