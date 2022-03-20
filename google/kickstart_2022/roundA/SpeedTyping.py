a = int(input())
for tc in range(a):
    s = input()
    s_ = input()
    i = 0
    j = 0
    dl = 0
    while True:
        if i >= len(s) or j >= len(s_):
            break
        if s[i] == s_[j]:
            i += 1
            j += 1
        else:
            j += 1
            dl += 1
    if i == len(s):
        print("Case #{}: {}".format(tc+1, dl+len(s_)-j))
    else:
        print("Case #{}: IMPOSSIBLE".format(tc+1))
