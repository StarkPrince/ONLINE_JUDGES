# Problem : https://www.codechef.com/START31B/problems/UNCHANGEDOR
# we can easily notice that for each number that contain only 1 set bet are the only number for which f(i) != f(i-1) thus decreasing their count

import math
for _ in range(int(input())):
    n = int(input())
    print(n-int(math.log(n, 2))-1)
