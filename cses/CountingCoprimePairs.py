maxN = 1000000

n = int(input())
cnt = [0]*maxN
a = [int(x) for x in input().split()]
for x in a:
    cnt[x] += 1

for i in range(1, maxN):
    for j in range(2*i, maxN, i):
        cnt[i] += cnt[j]
    cnt[i] = (cnt[i]*(cnt[i]-1))//2
for i in range(maxN, 0, -1):
    for j in range(2*i, maxN, i):
        cnt[i] -= cnt[j]

print(cnt[1])
