s = int(input())
d = [0]*4
d[0] = s % 10
s //= 10
d[1] = s % 10
s //= 10
d[2] = s % 10
s //= 10
d[3] = s % 10
s //= 10
d = sorted(d)
print((d[0]+d[1])*10+d[2]+d[3])
