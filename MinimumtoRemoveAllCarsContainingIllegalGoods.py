a = input()


def rm1(a, l, r, d):
    # print(len(d))
    if l == r:
        return 0
    rs = str(l) + "|" + str(r)
    if rs not in d:
        ans = 10**9
        ans = min(ans, 1 + min(rm1(a, l+1, r, d), rm1(a, l, r-1, d)))
        cnt = 0
        for i in range(l, r):
            if a[i] == "1":
                cnt += 2
        d[rs] = min(ans, cnt)
    return d[rs]


print(rm1(a, 0, len(a), {}))
