# https://leetcode.com/contest/weekly-contest-282/problems/minimum-time-to-complete-trips/

# easy binary search and just checking how many trips can be completed in the given time
# if the trips are equal or more, then shif the high time to mid
# else if the trips are less, then shift the low time to mid + 1, coz this is undesired result

time = [2]
totalTrips = 1

lo = 0
hi = 10**15


def calc(arr, x):
    ans = 0
    for i in arr:
        ans += x//i
    return ans


ans = 0
while(lo < hi):
    mid = (lo + hi) // 2
    if (calc(time, mid) < totalTrips):
        lo = mid + 1
    else:
        hi = mid

print(hi)
