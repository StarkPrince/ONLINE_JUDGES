def rotate(array, n):
    return array[n:] + array[:n]


a = [False]*360
n = int(input())
s = [int(i) for i in input().split()]
a[0] = True
for i in s:
    a = rotate(a, i)
    a[0] = True
mn = 0
mx = -10**9
for i in range(360):
    if a[i]:
        mx = max(mx, i-mn)
        mn = i
mx = max(mx, 360-mn)
print(mx)
