#
# ?Problem: https://codeforces.com/contest/1793/problem/B
# *Solution: we can see that the answer is always 2 * (n - m) and the array is always the same and it is the same as the array of the first n - m numbers and the array of the last n - m numbers in reverse order

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(2 * (n - m))
    for i in range(m, n + 1):
        print(i, end=" ")
    for i in range(n - 1, m, -1):
        print(i, end=" ")
    print()
