def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

n = int(input())
mp = [{} for i in range(n+1)]
tp = [int(i) for i in input().split()]

for i in range(1,n+1):
    ex = tp[i-1]
    mp[i][ex] = 1
    for gcdcurr,len in mp[i-1].items():
        print(gcdcurr,len,ex)
        v = gcd(gcdcurr,ex)
        mp[i][v] = mp[i].get(v,0) + len

print(mp)

real = {}
for i in range(1,n+1):
    for gcdcurr,len in mp[i].items():
        real[gcdcurr] = real.get(gcdcurr,0) + len


q = int(input())
for i in range(q):
    ex = int(input())
    print(real.get(ex,0))