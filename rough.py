def countVowelStrings(n) :
    arr = [1,1,1,1,1]
    for i in range(n-1):
        narr = [arr[0],0,0,0,0]
        for j in range(1,5):
            narr[j] = narr[j-1] + arr[j]
        arr = narr
    return sum(arr)

print(countVowelStrings(33))