from collections import deque

for _ in range(int(input())):
    n, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    d = {}
    for i in range(n):
        if a[i] not in d:
            d[a[i]] = 0
        d[a[i]] += 1
    ans = 0
    st = sorted(d.keys())
    for i in range(len(st)):
        s = st[i]
        if s*x in d and s in d and d[s*x] > d[s]:
            d[s*x] -= d[s]
        elif s*x in d and s in d and d[s*x] <= d[s]:
            ans += d[s] - d[s*x]
            del d[s*x]
        elif s in d:
            ans += d[s]
        if s in d:
            del d[s]
    print(ans)
