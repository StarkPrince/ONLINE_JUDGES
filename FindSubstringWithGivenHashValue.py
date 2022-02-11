# learn rabin karp algorithm

class Solution:
    def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
        dp = [0]
        for i in range(len(s)):
            dp.append(dp[-1] + (ord(s[i])-96)*self.binpow(power, i, modulo))
        for i in range(len(s)-k):
            if ((dp[i+k] - dp[i]) * self.binpow(self.binpow(power, i, modulo), modulo-2, modulo)) % modulo == hashValue:
                return s[i:i+k]
        return s

    def hashit(self, s, power, modulo):
        ans = 0
        for i in range(len(s)):
            ans += (ord(s[i])-96)*self.binpow(power, i, modulo)
            ans %= modulo
        return ans

    def binpow(self, a, b, m):
        a %= m
        res = 1
        while b > 0:
            if b & 1:
                res = res * a
                res %= m
            a *= a
            a %= m
            b >>= 1
        return res
