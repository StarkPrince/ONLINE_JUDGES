a = input()
# count no of consecutive a from backward
r = len(a)-1
ctr = 0
while r >= 0:
    if a[r] == 'a':
        r -= 1
        ctr += 1
    else:
        break
ctr2 = 0
l = 0
while l < len(a):
    if a[l] == 'a':
        l += 1
        ctr2 += 1
    else:
        break
a = "a"*(max(ctr-ctr2, 0)) + a
print("Yes" if a == a[::-1] else "No")
