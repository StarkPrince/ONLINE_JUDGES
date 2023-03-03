for _ in range(int(input())):
    n,m = map(int,input().split())
    print(2*(n-m))
    for i in range(m,n+1):
        print(i,end=" ")
    for i in range(n-1,m,-1):
        print(i,end=" ")
    print()