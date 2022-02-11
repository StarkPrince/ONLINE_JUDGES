for _ in range(int(input())):
    a = input()
    zero = one = 0
    for i in a:
        if i == '0':
            zero += 1
        else:
            one += 1
    if zero == one:
        print(zero-1)
    else:
        print(min(zero, one))
