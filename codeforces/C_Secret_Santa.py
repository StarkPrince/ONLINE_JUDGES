# Problem : https://codeforces.com/problemset/problem/1530/D

for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * (n+1)
    rem = []

    for k in a:
        cnt[k] += 1
    # create a counter array of the list
    for i in range(1, n+1):
        if cnt[i] == 0:
            rem.append(i)
    # append all those missing elements in the remaining section
    b = []
    tmp = 0
    for i in range(n):
        # push the remainder last element its not equal to i+1
        if cnt[a[i]] > 1 and rem and rem[-1] != i+1:
            b.append(rem[-1])
            rem.pop()
            cnt[a[i]] -= 1
        else:
            b.append(a[i])
            tmp += 1
    print(tmp)
    print(*b)
