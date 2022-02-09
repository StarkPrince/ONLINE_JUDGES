from cmath import log


for _ in range(int(input())):
    n, x, y = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    even = 0
    odd = 0
    for i in a:
        if i % 2 == 1:
            odd += 1
    if (x+odd) % 2 == y % 2:
        print("Alice")
    else:
        print("Bob")
