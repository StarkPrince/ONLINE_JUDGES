
# ?Problem : https://codeforces.com/contest/614/problem/A
# *Solution : just check if its crossing the 64 bit limit or not

l, r, k = map(int, input().split())
ans = 1

ok = False
while ans <= r:
    if ans >= l:
        print(ans, end=" ")
        ok = True
    ans *= k
if not ok:
    print(-1)
