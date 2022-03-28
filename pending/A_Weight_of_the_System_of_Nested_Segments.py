for _ in range(int(input())):
    s = input()
    n, m = map(int, input().split())
    d = {}
    for i in range(m):
        x, v = map(int, input().split())
        d[x] = [v, i+1]
    d = sorted(d.items(), key=lambda x: x[1][0])[:2*n]
    sm = 0
    points = []
    for i, j in d:
        sm += j[0]
    print(sm)
    d = sorted(d, key=lambda x: x[0])
    for i in range(n):
        print(d[i][1][1], d[2*n-i-1][1][1])
    print()