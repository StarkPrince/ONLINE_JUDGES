for tc in range(int(input())):
    n,k = map(int,input().split())
    e = list(map(int,input().split()))
    sm = sum(e)
    tm = sum([i*i for i in e])
    ans = "IMPOSSIBLE"
    nm = tm - sm*sm
    if sm==0 and nm==0:
        print("Case #{}: {}".format(tc+1,"0"))
    elif sm!=0 and nm%(2*sm) ==0 and abs(nm//(2*sm)) <=10**18:
        print("Case #{}: {}".format(tc+1,nm//(2*sm)))
    else:
        print("Case #{}: {}".format(tc+1,ans))