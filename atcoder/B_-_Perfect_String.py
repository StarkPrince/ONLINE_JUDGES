# 
# ?Problem:  https://atcoder.jp/contests/abc249/tasks/abc249_b
# *Solution: shitty question, just check if the string satisfies the condition or not 

s = input()
st = set(list(s))
bl = True
if len(st)<len(s):
    bl = False
tl = False
for i in range(65,91):
    if chr(i) in st:
        tl = True
if not tl:
    bl = False
tl = False
for i in range(97,123):
    if chr(i) in st:
        tl = True
if not tl:
    bl = False
if bl:
    print('Yes')
else:
    print('No')