#
# ?Problem : https://atcoder.jp/contests/abc247/tasks/abc247_d
# *Solution : for every insertion, add the value of sum of all number inserted till now along with no of balls inserted till now and for every deletion , take a track of how many balls were deleted earlier and then starting from that index, traverse through the list index and see if the no of balls inserted till now is less than the no of balls available till now, and continue to add the values of balls till then and in case of partial ball selection of a list, use the fractional part of the value of balls inserted till now and then add the value of balls available till now.


n = int(input())
v = []
v.append((0, 0))
sm = 0
balls = 0
taken_balls = 0
index = 1
for i in range(n):
    query = [int(i) for i in input().split()]
    if query[0] == 1:
        sm += query[1] * query[2]
        balls += query[2]
        v.append((balls, sm))
    else:
        ans = 0
        mu = taken_balls + query[1]
        while v[index][0] < mu:
            k = min(mu, v[index][0]) - taken_balls
            up = v[index][1] - v[index - 1][1]
            down = v[index][0] - v[index - 1][0]
            ans += (up // down) * k
            taken_balls += k
            index += 1
        k = min(mu, v[index][0]) - taken_balls
        up = v[index][1] - v[index - 1][1]
        down = v[index][0] - v[index - 1][0]
        ans += (up // down) * k
        taken_balls += k
        print(ans)
