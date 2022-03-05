MOD = 998244353


# def helper(num, steps, dp):
#     if steps == 0 or num == 0 or num == 10:
#         return 0
#     if steps == 1:
#         dp[num][steps] = 1
#     if dp[num][steps] != -1:
#         return dp[num][steps] % 998244353
#     dp[num][steps] = helper(num + 1, steps - 1, dp) + \
#         helper(num, steps - 1, dp) + helper(num - 1, steps - 1, dp)
#     return dp[num][steps] % 998244353


n = int(input())
dp = [[-1 for i in range(1000005)] for j in range(9)]

for j in range(n):
    for i in range(9):
        if j == 0:
            dp[i][j] = 1
        elif i == 0:
            dp[i][j] = dp[i][j-1] + dp[i+1][j-1]
        elif i == 8:
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i+1][j-1] + dp[i][j-1]


sm = 0
for i in range(9):
    sm += dp[i][n-1]
print(sm % MOD)
