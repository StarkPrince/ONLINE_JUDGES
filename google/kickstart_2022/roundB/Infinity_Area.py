pie = 3.14159265358979323846

for tc in range(int(input())):
    r,a,b = [int(i) for i in input().split()]
    ans = 0
    while(r!=0):
        ans += r*r
        r *= a
        ans += r*r
        r //= b
    ans *= pie
    print(f'Case #{tc+1}: {ans:.6f}')