# 
# ?Problem: https://atcoder.jp/contests/abc248/tasks/abc248_a
# *Solution: just find the missing string 


a = input()
for i in range(10):
    if str(i) not in a:
        print(i)
        break