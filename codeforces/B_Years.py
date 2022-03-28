# Problem : https://codeforces.com/gym/374813/problem/B

# easy peasy question, use the dict and store all the distinct years in a list and for starting an year incease the year by 1 and for ending decrease it by 1 as the person was born has died and then in increasing order, continue to sum them up and get what is the maximum amount of person can be alive at the same time and in which year

d = {}
for _ in range(int(input())):
    x, y = [int(i) for i in input().split()]
    if x not in d:
        d[x] = 0
    if y not in d:
        d[y] = 0
    d[x] += 1
    d[y] -= 1
mx = -1
mxy = None
carr = 0
for i in sorted(d):
    carr += d[i]
    if carr > mx:
        mx = carr
        mxy = i
print(mxy, mx)
