# https://atcoder.jp/contests/abc243/tasks/abc243_c
#  store the right most person who is willing to go left and left most person who is willing to go right for distinct y
#  if for the same y, the left going willing person is right to the right going willing person then print "Yes" else iterate over all y's and if no such y exists then print "No"

inf = 10**10

n = int(input())
mp = {}
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
direction = input()
for i in range(n):
    [x, y] = a[i]
    if direction[i] == 'L':
        if y not in mp:
            mp[y] = [x, inf]
        else:
            if mp[y][0] < x:
                mp[y][0] = x
    else:
        if y not in mp:
            mp[y] = [-inf, x]
        else:
            if mp[y][1] > x:
                mp[y][1] = x
for i, j in mp.items():
    if j[1] <= j[0]:
        print("Yes")
        exit()
print("No")

# for i, j in mp.items():
#     print(i, "=>", *j)
