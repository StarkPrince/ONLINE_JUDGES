nums = [int(x) for x in input().split()]
even = []
eveni = []
odd = []
oddi = []
for i in range(len(nums)):
    if i % 2 == 0:
        even.append(nums[i])
        eveni.append(i)
    else:
        odd.append(nums[i])
        oddi.append(i)
even.sort()
odd.sort(reverse=True)
for i in range(len(eveni)):
    nums[eveni[i]] = even[i]
for i in range(len(oddi)):
    nums[oddi[i]] = odd[i]
print(*nums)
