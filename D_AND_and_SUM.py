MaxBit = 90


def possiblePair(and_, sum_):
    or_ = sum_ - and_
    if (or_ < 0):
        return False

    for k in range(MaxBit):
        bit1 = (or_ >> k)
        bit2 = (and_ >> k)
        if (bit1 == 1 and bit2 == 1):
            return False
    return True


for _ in range(int(input())):
    a, s = map(int, input().split())
    if s >= a:
        print("Yes")
    else:
        print("No")
