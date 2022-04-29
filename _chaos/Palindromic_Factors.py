pal = {}
for i in range(1,100000):
    pal[i] = 0
    if str(i) == str(i)[::-1]:
        pal[i] = 1

def factors(n):
    factor = 1
    if n!=1 and str(n) == str(n)[::-1]:
        factor += 1
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            a,b = i,n//i
            if a==b and a in pal:
                factor += pal[a]
            elif b<100000 and a in pal and b in pal:    
                factor += pal[a] + pal[b]
            elif a in pal:
                factor += pal[a] 
                factor += 1 if str(b) == str(b)[::-1] else 0
    return factor

for tc in range(int(input())):
    n = int(input())
    ans = factors(n)
    print("Case #{}: {}".format(tc + 1, ans))
