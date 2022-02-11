# given a 2d matrix print its transpose
def transpose(arr, n, m):
    ans = [[0 for i in range(n)] for j in range(m)]
    for i in range(n):
        for j in range(m):
            ans[j][i] = arr[i][j]
    return ans


n, m = [int(x) for x in input().split()]
arr = []
for i in range(n):
    arr.append([int(x) for x in input().split()])
for i in transpose(arr, n, m):
    print(*i)
