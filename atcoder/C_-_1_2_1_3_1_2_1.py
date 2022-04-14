#
# ?Problem :https://atcoder.jp/contests/abc247/tasks/abc247_c
# *Solution : shitty question and no need for any explanation
s = "1"
n = int(input())
ans = ""
for i in range(2, n+1):
    s = s + " " + str(i) + " " + s
print(s)
