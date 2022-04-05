for i in range(int(input())):
    s = input()
    s1 = ""
    l = len(s)
    for j in s:
        if j in s1:
            l -= 2
            s1 = ""
        else:
            s1 = s1+j
    print(l)
