from collections import deque

n = int(input())
balls = list(map(int, input().split()))
ctr = 1
qu = 0
nqu = deque()
nqu.append([-1, 0])
for ball in balls:
    qu += 1
    if ball == nqu[-1][0]:
        ctr = nqu[-1][1] + 1
        nqu[-1][1] += 1
    else:
        ctr = 1
        nqu.append([ball, ctr])
    if ctr == ball:
        qu -= ball
        nqu.pop()
    lt = ball
    print(qu)
