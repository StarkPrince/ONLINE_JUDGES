a = [1 for _ in range(1000001)]

for i in range(2, 1000):
    for j in range(1, 1000001//i):
        a[i*j] += 1

print(a[:20])

# for i in range(int(input())):
#     b = int(input())
#     print(a[b])
