for tc in range(int(input())):
    r,c = map(int,input().split())
    # vector<vector<ll>> vect(2 * r, vector<ll>(2 * c, 0));
    # for (int i = 0; i < r; i++)
    # {
    #     for (int j = 0; j < c; j++)
    #     {
    #         char d;
    #         cin >> d;
    #         if (d == '#')
    #         {
    #             vect[2 * i][2 * j] = 1;
    #             vect[2 * i + 1][2 * j] = 1;
    #             vect[2 * i][2 * j + 1] = 1;
    #             vect[2 * i + 1][2 * j + 1] = 1;
    #         }
    #     }
    # }
    v = []
    for i in range(2*r):
        v.append([])
        for j in range(2*c):
            v[i].append(0)
    for i in range(r):
        j = input()
        for d in j:
            if d == '#':
                v[2*i][2*j] = 1
                v[2*i+1][2*j] = 1
                v[2*i][2*j+1] = 1
                v[2*i+1][2*j+1] = 1
    ans = "S"
    r*=2
    c*=2
    cr=1
    cc=0
    v[0][0]=0
    v[1][0]=1
    rv = [0,1,0,-1]
    rc = [-1,0,+1,0]
    while(cr!=0 or cc!=0):
        if(cr+rv[0]<r and cr+rv[0]>=0 and cc+rc[0]<c and cc+rc[0]>=0 and v[cr+rv[0]][cc+rc[0]]!=1):
            ans+='W'
            v[cr+rv[0]][cc+rc[0]]=1
            cr+=rv[0]
            cc+=rc[0]
        elif(cr+rv[1]<r and cr+rv[1]>=0 and cc+rc[1]<c and cc+rc[1]>=0 and v[cr+rv[1]][cc+rc[1]]!=1):
            ans+='S'
            v[cr+rv[1]][cc+rc[1]]=1
            cr+=rv[1]
            cc+=rc[1]
        elif(cr+rv[2]<r and cr+rv[2]>=0 and cc+rc[2]<c and cc+rc[2]>=0 and v[cr+rv[2]][cc+rc[2]]!=1):
            ans+='E'
            v[cr+rv[2]][cc+rc[2]]=1
            cr+=rv[2]
            cc+=rc[2]
        elif(cr+rv[3]<r and cr+rv[3]>=0 and cc+rc[3]<c and cc+rc[3]>=0 and v[cr+rv[3]][cc+rc[3]]!=1):
            ans+='N'
            v[cr+rv[3]][cc+rc[3]]=1
            cr+=rv[3]
            cc+=rc[3]
        else:
            break
    print("Case #{}: {}".format(tc+1,ans))