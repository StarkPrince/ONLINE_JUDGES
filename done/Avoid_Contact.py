for _ in range(int(input())):
    x, y = [int(i) for i in input().split()]
    if y == 0:
        print(x)
    elif y == 1:
        if x == 1:
            print(1)
        else:
            print(x+1)
    else:
        print(x + y if x > y else x + y - 1)
