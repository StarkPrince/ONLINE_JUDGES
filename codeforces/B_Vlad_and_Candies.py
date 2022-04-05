# Problem:  https://codeforces.com/contest/1660/problem/B

# retared question, just return yes if the diffence between the max and second max element is less than 2

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    # get the max element and the second max element
    max_a = max(a)
    max_a_index = a.index(max_a)
    smax = 0
    for i in range(n):
        if i != max_a_index:
            smax = max(smax, a[i])
    if max_a-smax < 2:
        print("YES")
    else:
        print("NO")
