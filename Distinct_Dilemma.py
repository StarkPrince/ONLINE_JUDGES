for _ in range(int(input())):
    n = int(input())
    s = [int(x) for x in input().split()]
    sm = sum(s)
    print(int(((8*sm + 1)**0.5 - 1)/2))
