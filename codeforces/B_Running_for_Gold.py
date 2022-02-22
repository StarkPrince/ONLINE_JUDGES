for _ in range(int(input())):
    n = int(input())
    m = []
    for i in range(n):
        m.append(list(map(int, input().split())))
    a = 0
    for j in range(1,n):
        if sum([1 for i in range(5) if m[a][i] < m[j][i]])<3:
            a = j
    k = [sum([1 for i in range(5) if m[a][i]<=m[j][i]]) for j in range(n)]
    if min(k)>=3:
        print(a+1)
    else:
        print(-1)