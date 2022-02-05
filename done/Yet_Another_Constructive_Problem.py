for i in range(int(input())):
    n = int(input())
    a = b = 0
    c = n
    if n == 1:
        a = 3
        b = 5
    elif n % 2 == 1:
        a = n - 2
        b = n - 1
    else:
        a = n + 2
        b = n + 1
    print(a, b, c)
