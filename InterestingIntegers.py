for tc in range(int(input())):
    a, b = map(int, input().split())
    cnt = 0
    for i in range(a, b+1):
        n = str(i)
        sm = sum(map(int, n))
        prod = 1
        for j in n:
            prod *= int(j)
        if prod % sm == 0:
            cnt += 1
    print("Case #{}: {}".format(tc+1, cnt))
