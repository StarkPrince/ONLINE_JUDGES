# Problem : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
# shitty question we just have to sort the array and find the maximum increasing sequence we can make

for tc in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    a = sorted(a)
    ctr = 1
    ans = 0
    for i in range(n):
        if a[i] >= ctr:
            ans += 1
            ctr += 1
    print("Case #{}: {}".format(tc+1, ans))
