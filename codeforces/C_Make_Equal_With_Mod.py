# Problem : https://codeforces.com/contest/1656/problem/C

# if the numbers have the same parity then we can divide a of them by 2 and we get the answer, they all are greater than 2 we can individally divide them with themselved and make every numeber zero
# if 1 in in d consecutive number cant be present in the list if they are, print NO else yes

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    d = {}
    for i in a:
        if i not in d:
            d[i] = 0
        d[i] += 1
    # check if all number are of same parity
    bl = all(i >= 2 for i in d.keys())
    if bl:
        print("YES")
    elif 1 in d and 0 in d:
        print("NO")
    elif 1 in d:
        bl = True
        for i in d.keys():
            if i+1 in d:
                bl = False
                break
        print("YES" if bl else "NO")
    else:
        print("YES")
