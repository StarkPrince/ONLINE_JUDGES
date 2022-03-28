# Problem : https://codeforces.com/gym/374813/problem/D

#  store the array in a deque and while the deque exist add the time taken with current speed to reach the next flag from both the directions and for each flag increase the speed, thus calculating the time taken to meet them up.

from collections import deque

for _ in range(int(input())):
    b, du = list(map(int, input().split()))
    c = deque(map(int, input().split()))
    v = u = 1
    h = i = dv = 0
    while c:
        if (c[0]-dv)/v <= (du-c[-1])/u:
            e, dv = (c[0]-dv)/v, c[0]
            h += e
            v += 1
            c.popleft()
            if c:
                if e*u >= (du-c[-1]):
                    f, du = (du-c[-1])/u, c[-1]
                    c.pop()
                    u += 1
                    if(e > f):
                        du -= (e-f)*u
                else:
                    du -= u*e
            else:
                du -= u*e
        else:
            e, du = (du-c[-1])/u, c[-1]
            h += e
            u += 1
            c.pop()
            if c:
                if e*v >= (c[0]-dv):
                    f, dv = (c[0]-dv)/v, c[0]
                    c.popleft()
                    v += 1
                    if e > f:
                        dv += (e-f)*v
                else:
                    dv += v*e
            else:
                dv += v*e
    h += (du-dv)/(u+v)
    print(h)
