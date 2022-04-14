#
# ?Problem : https://codeforces.com/contest/1660/problem/C
# *Solution : we can continue to remove characters if we get an even number of amount otherwise if they are equal to the last character

for i in range(int(input())):
    s = input()
    s1 = ""
    l = len(s)
    for j in s:
        if j in s1:
            l -= 2
            s1 = ""
        else:
            s1 += j
    print(l)
