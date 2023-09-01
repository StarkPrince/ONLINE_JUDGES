# ?Problem : https://codeforces.com/contest/468/problem/A
# *Solution : if n <= 3, then there is no solution. Otherwise, we can construct a solution as follows:

n = int(input())
if n <= 3:
    print("NO")
else:
    print("YES")
    if n % 2 == 0:
        print("1 * 2 = 2")
        print("2 * 3 = 6")
        print("6 * 4 = 24")
        for i in range(5, n, 2):
            print("%d - %d = 1" % (i + 1, i))
            print("24 * 1 = 24")
    else:
        print("2 - 1 = 1")
        print("1 + 3 = 4")
        print("4 * 5 = 20")
        print("20 + 4 = 24")
        for i in range(6, n, 2):
            print("%d - %d = 1" % (i + 1, i))
            print("24 * 1 = 24")
