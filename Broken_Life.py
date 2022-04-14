for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    t = input()
    pos = 0
    ans = ""
    works = True
    for c in s:
        if c == '?':
            ans += 'a' if t[pos] == 'd' else 'd'
        else:
            ans += c
            if c == t[pos]:
                pos += 1
            if pos == m:
                works = False
                break

    if works:
        print(ans)
    else:
        print(-1)
