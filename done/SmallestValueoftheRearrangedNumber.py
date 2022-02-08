def largest(arr):
    arr.sort(reverse=True)
    return int("".join(map(str, arr)))


def smallest(arr):
    if '0' not in arr:
        arr.sort()
        return int("".join(map(str, arr)))
    cnt = arr.count('0')
    arrwithoutzero = [x for x in arr if x != '0']
    arrwithoutzero.sort()
    return int(str(arrwithoutzero[0]) + '0' * cnt + "".join(map(str, arrwithoutzero[1:])))


nums = int(input())
if nums < 0:
    print(-largest(list(str(-nums))))
else:
    print(smallest(list(str(nums))))
