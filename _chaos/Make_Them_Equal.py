for _ in range(int(input())):
    n = int(input())
    s = [int(x) for x in input().split()]
    o, e = 0, 0
    for i in s:
        if i % 2 == 1:
            o += 1
        else:
            e += 1
    if o == 0 or e == 0:
        print(0)
    elif o % 2 == 0:
        print(min(o//2, e))
    else:
        print(e)
# O-O, E-E
# 7
# 2 4 4 4 3 3 3
# 5
# 3 3 3 4 4
# 11
# 3 3 3 4 4 4 4 4 4 4 4
# O-O, E-O
# 4
# 3 3 3 4
# 8
# 3 3 3 4 4 4 4 4
# O-E, E-E
# O-E, E-O
# 5
# 2 2 3 3 3
