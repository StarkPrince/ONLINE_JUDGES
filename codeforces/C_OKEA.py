for _ in range(int(input())):
    n, k = [int(i) for i in input().split()]
    if k == 1:
        print("YES")
        for i in range(n):
            print(i+1)
    elif n % 2 == 1:
        print("NO")
    else:
        print("YES")
        odd = 1
        even = 2
        for i in range(n//2):
            for j in range(k):
                print(odd, end=" ")
                odd += 2
            print()
            for j in range(k):
                print(even, end=" ")
                even += 2
            print()
