# solution was okay but tle on last case due to python

def pp(vc, ix, sm,  dp):
    if ix == len(vc):
        return 1 if sm == 0 else 0
    if dp[ix][sm] != -1:
        return dp[ix][sm]
    else:
        x = vc[ix][0]
        y = vc[ix][1]
        if (sm >= x and pp(vc, ix + 1, sm - x, dp)) or (sm >= y and pp(vc, ix + 1, sm - y, dp)):
            dp[ix][sm] = 1
        else:
            dp[ix][sm] = 0
        return dp[ix][sm]


n, x = [int(i) for i in input().split()]
vc = []
for i in range(n):
    vc.append([int(i) for i in input().split()])
dp = [[-1 for i in range(x + 1)] for j in range(n + 1)]
print("Yes" if pp(vc, 0, x, dp) else "No")
