import itertools

for tc in range(int(input())):
    n = int(input())
    st = input().split()
    bl = False
    fans = ""
    for perm in itertools.permutations(st):
        ans = "".join(perm)
        i = 0
        ch = set()
        ls = ""
        tl = True
        tans = ans[0]
        for i in range(1,len(ans)):
            if ans[i] != ans[i-1]:
                tans += ans[i]
        if len(tans) == len(set(tans)):
            bl = True
            fans = ans
            break
    if bl:
        print("Case #{}: {}".format(tc+1,fans))
    else:
        print("Case #{}: {}".format(tc+1,"IMPOSSIBLE"))