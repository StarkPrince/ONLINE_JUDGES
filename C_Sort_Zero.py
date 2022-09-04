for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    st = set()
    mn = 10**9
    ans = 0
    for i in range(n-1, -1, -1):
        print(st)
        print(mn, i, a[i])
        if a[i] <= mn:
            mn = min(mn, a[i])
            continue
        else:
            if a[i] not in st:
                ans += 1
                st.add(a[i])
                mn = 0
    print("\n")
    print(ans)
