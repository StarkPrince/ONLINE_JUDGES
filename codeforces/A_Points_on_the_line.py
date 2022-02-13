# https://codeforces.com/contest/940/problem/A
# easy - peasy question
#  just sort the array and then check if the difference is less than d by removing the first element or the last element and then check how bigger array can be made

do = [[-1 for i in range(105)] for j in range(105)]

def max_length(points,d,l,r):
    if l>=r or points[r] <= points[l] + d:
        return r-l+1
    if do[l][r] == -1:
        do[l][r] = max(max_length(points,d,l+1,r),max_length(points,d,l,r-1))
    return do[l][r]

n, d = [int(i) for i in input().split()]
a = sorted([int(i) for i in input().split()])

print(n-max_length(a,d,0,n-1))
