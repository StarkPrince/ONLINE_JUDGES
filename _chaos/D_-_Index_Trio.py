n = int(input())
a = [int(i) for i in input().split()]
m = {}
for i in a:
    if i not in m:
        m[i] = 0
    m[i] += 1
ans = 0
# count triplets i,j,k such that i*j = k
for i in range(1,500):
    for j in m:
        if j>=i:
            s = 0
            if i==j==1 and 1 in m:
                k = m[1]
                s = k**3
            elif (i==1 or j==1) and 1 in m and i*j in m:
                k = m[i*j]
                s = k*(k-1)*2*m[1]
            elif i==j and i*j in m:
                k = m[i]
                s = k*(k-1)*m[i*j]
            elif i in m and i*j in m:
                k = m[i*j]
                s = k*m[i]*m[j]*2
            ans += s
            if s>0:
                print(i,j,s)
print(ans)