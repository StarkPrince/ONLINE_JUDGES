# 
# ?Problem:  https://acm.timus.ru/problem.aspx?space=1&num=1100
# *Solution: just bubble sort

n = int(input( ))
d = []
for i in range(n):
    d.append([int(x) for x in input().split()])
    
while True:
    flag = False
    for i in range(n-1):
        if d[i][1] < d[i+1][1]:
            d[i],d[i+1] = d[i+1],d[i]
            flag = True
    if not flag:
        break

for i in range(n):
    print(d[i][0], d[i][1])