#
#  ?Problem : https://atcoder.jp/contests/abc247/tasks/abc247_b
#  *Solution: Easy peasy just check if either of the name are unique to all of the other names.

n = int(input())
d = {}
names = []
for _ in range(n):
    s, t = input().split()
    names.append([s, t])
    if s not in d:
        d[s] = 0
    if t not in d:
        d[t] = 0
    d[s] += 1
    d[t] += 1

bl = True
for name in names:
    s, t = name
    d[s] -= 1
    d[t] -= 1
    if d[s] != 0 and d[t] != 0:
        bl = False
        break
    d[s] += 1
    d[t] += 1
print("Yes" if bl else "No")
