def subStrHash(s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
    dp = [0]
    for i in range(len(s)):
        dp.append(dp[-1] + (ord(s[i])-96)*binpow(power, i, modulo))
    for i in range(len(s)-k):
        print(dp[i+k]-dp[i], s[i:i+k])
        if ((dp[i+k] - dp[i]) // binpow(power, i, modulo-2)) % modulo == hashValue:
            return s[i:i+k]
    return s


def binpow(a, b, m):
    # a %= m
    res = 1
    while b > 0:
        if b & 1:
            res = res * a
            # res %= m
        a *= a
        # a %= m
        b >>= 1
    return res


print(subStrHash("xxterzixjqrghqyeketqeynekvqhc", 15, 94, 4, 16))
