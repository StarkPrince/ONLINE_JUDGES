def countHillValley(nums):
    hill = 0
    valley = 0
    sm = nums[0]
    modifiedNums = []
    for i in range(len(nums)-1):
        if nums[i] != nums[i+1]:
            modifiedNums.append(nums[i])
    modifiedNums.append(nums[-1])

    for i in range(1, len(modifiedNums)-1):
        if modifiedNums[i] > modifiedNums[i+1] and modifiedNums[i] > modifiedNums[i-1]:
            valley += 1
        elif modifiedNums[i] < modifiedNums[i+1] and modifiedNums[i] < modifiedNums[i-1]:
            hill += 1

    return hill + valley


print(countHillValley([6, 6, 5, 5, 4, 1]))
print(countHillValley([2, 4, 1, 1, 6, 5]))
