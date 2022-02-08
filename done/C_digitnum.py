n = int(input())
ans = (n*(n+1)//2) % 998244353
s = len(str(n))
while(n > 0):
    lo = int("9"*(s-1) if s > 1 else 0)
    other = n-lo
    ans -= other*(lo)
    n = lo
    s = len(str(n))
ans -= n*(n+1)//2
print((ans + 998244353) % 998244353)
