for i in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    if n == 2:
        print(min(arr))
    else:
        arr = sorted(arr)
        print(arr[-2])
