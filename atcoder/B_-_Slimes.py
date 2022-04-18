# 
# ?Problem:  https://atcoder.jp/contests/abc248/tasks/abc248_b
# *Solution: Just keep multiplying the number of slimes by k while its less than k and print the number of steps.

a,b,x = [int(x) for x in input().split()]
ctr = 0
while(a<b):
    a *= x
    ctr += 1
print(ctr)