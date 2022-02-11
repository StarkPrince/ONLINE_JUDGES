for _ in range(int(input())):
    n = int(input())
    s = input()
    if n > 2:
        print("NO")
    elif n == 2:
        if s[0] == s[1]:
            print("NO")
        else:
            print("YES")
    else:
        print("YES")
