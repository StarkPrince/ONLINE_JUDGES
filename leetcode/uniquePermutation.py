def uniquepermutation(arr):
    if len(arr) == 1:
        return [arr]
    else:
        result = []
        for i in range(len(arr)):
            newarr = arr[:i] + arr[i+1:]
            for j in uniquepermutation(newarr):
                result.append([arr[i]] + j)
        return result

print(uniquepermutation([1,2,3]))