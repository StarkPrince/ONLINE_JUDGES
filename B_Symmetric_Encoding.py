for _ in range(int(input())):
    n = int(input())
    s = input()
    fns = sorted(list(set(s)))
    dct = {}
    for i in range(len(fns)):
        dct[fns[i]] = fns[len(fns)-1-i]
    ans = ""
    for i in s:
        ans += dct[i]
    print(ans)