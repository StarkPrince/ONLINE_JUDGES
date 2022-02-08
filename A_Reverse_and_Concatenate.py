def isPalindrome(n):
    return n == n[::-1]


for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    if k == 0:
        print(1)
    elif isPalindrome(s):
        print(1)
    else:
        print(2)
