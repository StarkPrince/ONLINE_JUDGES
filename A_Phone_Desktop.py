for _ in range(int(input())):
    x,y = map(int,input().split())
    area = x*1+y*4
    cnt = (y-1)//2 + 1
    if 2*y<7*x and area > 15*cnt:
        print(cnt + (area- 15*cnt - 1)//15 + 1)
    else:
        print(cnt)
