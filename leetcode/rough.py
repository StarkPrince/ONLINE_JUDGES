def helper(A,i,j,n,m,dp):
    if i>=n or j>=m:
        return 0
    if i==n-1 and j==m-1 and A[i][j]!=1:
        return 1
    if A[i][j]==1:
        return 0
    if dp[i][j]!=-1:
        return dp[i][j]
    ans=helper(A,i+1,j,n,m,dp)+helper(A,i,j+1,n,m,dp)
    dp[i][j]=ans
    return ans
    
def uniquePathsWithObstacles(A):
    r=len(A)
    if r==0:
        return 0
    c=len(A[0])
    print(r,c)
    dp = [[-1 for i in range(c)] for j in range(r)]
    helper(A,0,0,r,c,dp)
    return dp[0][0]

print(uniquePathsWithObstacles([[0]]))