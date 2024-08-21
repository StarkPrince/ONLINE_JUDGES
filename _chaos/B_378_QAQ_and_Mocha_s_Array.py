for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    x = a[0]
    i = 0
    while i < n and a[i]%x == 0:
        i += 1
    if i == n:
        print("Yes")
    else:
        y = a[i]
        for j in range(n):
            if a[j]%x == 0 or a[j]%y == 0:
                continue
            else:
                print("No")
                break
        else:
            print("Yes")