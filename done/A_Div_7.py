def shit(n):
    s = n % 7
    if s == 0:
        return n
    elif n % 10 >= s:
        return n-s
    else:
        return n-s+7


for _ in range(int(input())):
    a = int(input())
    print(shit(a))
