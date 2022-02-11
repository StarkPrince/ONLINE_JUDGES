# https://codeforces.com/contest/778/problem/B

n, m = [int(x) for x in input().split()]
predefined_vars = {}
for i in range(n):
    var, expression = input().split(":=")
    form = expression.strip(" ").split(" ")
    if len(form) == 1:
        predefined_vars[var] = int(form[0])
    else:
        print(form)
t = max(map(len(str()), predefined_vars.values()))
print(t)
print(predefined_vars)
