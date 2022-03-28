# Problem : https://codeforces.com/contest/1656/problem/0
# Solution : just return the maximum and minimum index of the array

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    min_index = a.index(min(a))
    max_index = a.index(max(a))
    print(min_index+1, max_index+1)
