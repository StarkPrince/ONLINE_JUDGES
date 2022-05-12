for _ in range(int(input())):
    s = input()
    if len(set(s)) == 1 or len(set(s)) == len(s):
        print("YES")
    else:
        