def patt(arr,l,r,n):
    if len(arr) == 0:
        return 0
    # arr = [vect[0]]
    # for i in range(1,len(vect)):
    #     if vect[i]!=vect[i-1]:
    #         arr.append(v[i])
    if len(arr) == 1:
        return min(arr[0],n-arr[0])
    ans = 10**10
    print(arr)
    for i in range(len(arr)):
        if i == 0:
            k = min(arr[0],n-arr[0],abs(arr[1]-arr[0]))
            print(arr[i],k)
            ans = min(ans,k + patt(arr[1:],n))
        elif i == len(arr)-1:
            k = min(arr[i],n-arr[i],abs(arr[i]-arr[i-1]))
            print(arr[i],k)
            ans = min(ans,k + patt(arr[:i-1],n))
        else:
            k = min(arr[i],n-arr[i],abs(arr[i]-arr[i-1]),abs(arr[i]-arr[i+1]))
            print(arr[i],k)
            ans = min(ans,k + patt(arr[:i] + arr[i+1:],n))
    return ans

for tc in range(int(input())):
    n,d = map(int,input().split())
    v = [int(x) for x in input().split()]
    # vect = [v[0]]
    # for i in range(1,n):
    #     if v[i]!=v[i-1]:
    #         vect.append(v[i])
    print("Case #{}: {}".format(tc+1,patt(v,d)))