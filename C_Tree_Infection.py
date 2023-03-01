# for _ in [0] * int(input()):
#     n = int(input())
#     a = list(map(int, input().split()))
n = 6
a = [1, 1, 1, 1, 1]
c = [0] * n + [1]
for i in a:
    c[i - 1] += 1
c = sorted(c, reverse=True)
ans = sum(i > 0 for i in c)
for i, j in enumerate(c):
    if j > 0:
        c[i] = i + j - ans
c = sorted([i for i in c if i > 0], reverse=True)
print(*c)
while c:
    ans += 1
    for i, j in enumerate(c):
        if j > 0:
            c[i] = j - 1 - (i == 0)
    c = sorted([i for i in c if i > 0], reverse=True)
print(ans)
