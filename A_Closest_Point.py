for _  in range(int(input())):
    a = int(input())
    arr = list(map(int, input().split()))

    if len(arr)>2:
        print("NO")
    elif len(arr)==2 and abs(arr[1]-arr[0])==1:
        print("NO")
    else:
        print("YES")