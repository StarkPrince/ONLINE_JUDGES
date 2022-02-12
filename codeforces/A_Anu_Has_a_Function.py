# https://codeforces.com/contest/1299/problem/A
# Observation:
# 1 | 1 - 1 = 0
# 1 | 0 - 0 = 1
# 0 | 1 - 1 = 0
# 0 | 0 - 0 = 0
# takeaways:
# 1. if there are more than one element containing setbits at the same position, the final bit on that position is going to be non-set bit
# 2. if there is just one element containing setbits at a position, the final bit on that position is going to be set bit, only if the element in the leftmost position so better to find such an element whose one of the set bit is such that that position is filled with set bit in only that element and push that element to the leftmost position
# 3. if there is no such element, the final answer is 0 and we can return the original array


n = int(input())
A = [int(x) for x in input().split()]

bit = 2**30
while bit:
    B = []
    for i in range(n):
        if A[i] & bit:
            B.append(i)
    print(B)

    if len(B) == 1:
        print(' '.join(str(x) for x in [A[B[0]]] + A[:B[0]] + A[B[0] + 1:]))
        exit()
    bit >>= 1
print(' '.join(str(x) for x in A))
