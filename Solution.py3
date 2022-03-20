a = int(input())
for tc in range(a):
    n = int(input())
    st = str(n)
    sm = sum(map(int, st))
    rem = sm % 9
    bl = True
    if rem != 0:
        for i in range(len(st)):
            if int(st[i]) > 9-rem:
                st = st[:i] + str(9-rem) + st[i:]
                bl = False
                break
    else:
        bl = False
    if bl:
        st += str(9-rem)
    print("Case #{}: {}".format(tc+1, st))
