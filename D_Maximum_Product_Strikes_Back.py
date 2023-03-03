def getMax(arr):
    product = 1
    for i in arr:
        product *= i
    if product > 0:
        return [0, len(arr)-1, product]
    lt = rt = 1
    i = 0
    while (lt > 0 and rt > 0):
        lt *= arr[i]
        i += 1
    j = len(arr)-1
    while (rt > 0 and j >= 0):
        rt *= arr[j]
        j -= 1
    if abs(lt) >= abs(rt):
        return [0, j, product//rt]
    else:
        return [i, len(arr)-1, product//lt]


for _ in range(int(input())):
    n = int(input())
    v = [int(x) for x in input().split()]
    ct = 0
    for i in v:
        if i <= 0:
            ct += 1
    if ct == 0:
        print(0, 0)
        continue
    s = []
    temp = []
    for i in range(n):
        if v[i] != 0:
            temp.append(v[i])
        else:
            s.append(temp)
            temp = []
    s.append(temp)
    mx = 1
    ans = [0, -1]
    ctr = 0
    for arr in s:
        lt, rt, prod = getMax(arr)
        if prod > mx:
            ans = [ctr + lt, ctr + rt]
            mx = max(prod, mx)
        ctr += len(arr) + 1
    print(ans[0], n-ans[1] - 1)
