def helper(s, st):
    mn = "zz"
    for i in range(len(s)):
        if i in st:
            mn = min(mn, s[i])
    return mn


for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    if k >= 26:
        print("".join(sorted(list(s))))
    elif k == 1:
        print(s)
    else:
        m = []
        don = set(i for i in range(n))
        ctr = 0
        lsi = 0
        while ctr < k-1:
            temp = ""
            newrange = list(range(lsi, n)) + list(range(0, lsi))
            for i in newrange:
                mn = helper(s, don)
                lsi = -1
                if i in don:
                    if s[i] == mn:
                        don.remove(i)
                        temp += s[i]
                        lsi = i
            m.append(temp)
            ctr += 1
        if len(don) > 0:
            temp = ""
            mni = s[sorted(list(don))[0]]
            for i in range(lsi, n):
                if i in don and s[i] <= mni:
                    temp += s[i]

        print(m)
