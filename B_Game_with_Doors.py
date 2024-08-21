# Ili r2;
# cin>>ll>>rl;
# cin>>12>>r2;
# const Ili L=max(11,12) ,R=min(r1, r2);
# ntinue;
# Ili ans = R-L+I;
# ans++ ;
# if (max(rl, r2)>R)
# anS++ ;
# cout<<ans -1<<endI ;

for _ in range(int(input())):
    l1, r1 = map(int, input().split())
    l2, r2 = map(int, input().split())

    L = max(l1, l2)
    R = min(r1, r2)

    if R< L:
        print(1)
        continue

    print(R - L +  (l1 != l2) + (r1 != r2))
