# Problem : https://codeforces.com/gym/374813/problem/A
#  for all index other than 1 and lthe last one, the number of segrments to be removed is 1 more than their number of distinct occurences, so initialise the dict of all index with 1 and then for each number passing by increase it by 1 and then decrease the value of 1st and last index by 1 and now return the minimum element

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    d = {a: 1 for a in a}
    b = 0
    for i in a:
        if i != b:
            b = i
            d[i] += 1

    d[a[0]] -= 1
    d[a[-1]] -= 1
    print(min(d.values()))
