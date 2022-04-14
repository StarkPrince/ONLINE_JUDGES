d = {}
ctr = 1
for i in range(15):
    d[ctr] = 15 - i
    ctr *= 2

for i in range(32768):
    ctr = 1
    if i not in d:

    for j in range(20):
        k1 = i*ctr % 32768
        if k1 in d:
            d[i] = k1
        ctr *= 2

print(d[1])
# n = int(input())
# a = [int(x) for x in input().split()]
# for i in a:
#     print(d[i % 32768], end=' ')
