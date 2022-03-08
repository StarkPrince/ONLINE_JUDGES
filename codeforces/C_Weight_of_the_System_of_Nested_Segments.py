# https://codeforces.com/contest/1650/problem/C

# easy peasy question, store the value of each points along with their occurence in the nested segments
# and sort them by their weight, then return  top 2*n
# now sort the rest on the basis of their indicies
# and then return their occurence in the nested segments

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
