# 
# ?Problem:  https://codeforces.com/contest/1671/problem/A
# *Solution: there shouldnt be a single a or single b in the string

for _ in range(int(input())):
    s = input()
    d = set(list(s))
    d.add("a")
    d.add("b")
    if len(d)>2:
        print("NO")
    else:
        bl = True
        ls = ""
        streak = 0
        for i in range(len(s)):
            if s[i] == ls:
                streak += 1
            else:
                if streak == 1:
                    bl = False
                streak = 1
            ls = s[i]
        if streak == 1:
            bl = False
        if bl:
            print("YES")
        else:
            print("NO")