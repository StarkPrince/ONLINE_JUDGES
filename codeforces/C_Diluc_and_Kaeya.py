for _ in range(int(input())):
    n = int(input())
    d, k = 0, 0
    a = [0 for i in range(n)]
    s = input()
    for i in range(n):
        if s[i] == "D":
            d += 1
        else:
            k += 1
        if k == 0:
            a[i] = -1
        else:
            a[i] = d / k
    mp = {}
    for i in a:
        if i not in mp:
            mp[i] = 0
        mp[i] += 1
        print(mp[i], end=" ")
    print()
