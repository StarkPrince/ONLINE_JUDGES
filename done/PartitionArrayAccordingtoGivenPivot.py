nums = [9, 12, 5, 10, 14, 3, 10]
ans = []
pivot = 10
for i in nums:
    if i < pivot:
        ans.append(i)
for i in nums:
    if i == pivot:
        ans.append(i)
for i in nums:
    if i > pivot:
        ans.append(i)
print(ans)
