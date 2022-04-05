MOD = 10**9+7


def lastEqualIndex(arr1, l, r):
    lo = l
    hi = r
    while(lo <= hi):
        mid = (lo+hi)//2
        if arr1[mid] == arr1[r]:
            lo = mid+1
        else:
            hi = mid-1


# # print(lastEqualIndex([1, 3, 5, 7, 8], [1, 3, 5]))
# def string_hashing(word):
#     arr = [0]
#     ctr = 1
#     for i in word:
#         arr.append((arr[-1] + ord(i)*ctr) % MOD)
#         ctr *= 26
#         ctr %= MOD
#     print(arr)


string_hashing("aryanisaverycoolboy")
