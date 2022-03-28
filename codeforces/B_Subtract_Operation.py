# Problem : https://codeforces.com/contest/1656/problem/B
# for each number check if their suppliment is present in the array or not, like if n=0, check if they are present twice or not

for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    d = {}
    a = [int(x) for x in input().split()]
    for i in a:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    bl = True
    for i in d.keys():
        if k == 0 and d[i] > 1:
            bl = False
            break
        elif k != 0 and i-k in d:
            bl = False
            break
    if bl:
        print("NO")
    else:
        print("YES")
