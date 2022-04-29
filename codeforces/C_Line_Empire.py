# 
# ?Problem:  https://codeforces.com/contest/1659/problem/2
# *Solution: easy peasy greedy question

for _ in range(int(input())):
    n,a,b = [int(x) for x in input().split()]
    v = [int(x) for x in input().split()]
    v = [0] + v
    con = [0]*(n+1)
    for i in range(1,n+1):
        con[i] = (b*(v[i] - 0))
    for i in range(n-1,-1,-1):
        con[i] += con[i+1]
    cost = 0
    val = 0
    ans = 10**18
    for i in range(n):
        cost = v[i] *a
        if i !=0:
            val += ((v[i] - v[i - 1]) * b)
        cost += val
        rem = n-i
        rem *= v[i] *b
        cost += con[i+1] - rem
        ans = min(ans,cost)
    print(ans)