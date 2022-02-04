for _ in range(int(input())):
    n = int(input())
    s = input()
    if n % 2 == 1:
        print("NO")
        continue
    d = {}
    for i in s:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    if any(i > n//2 for i in d.values()):
        print("NO")
    else:
        s = "".join(sorted(list(s)))
        first = s[:n//2]
        second = s[n//2:]
        first = "".join(sorted(list(first), reverse=True))
        second = "".join(sorted(list(second)))
        print("YES")
        print(first+second)
