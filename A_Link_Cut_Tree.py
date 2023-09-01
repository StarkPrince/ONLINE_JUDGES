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
