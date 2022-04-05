# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
# easy peasy question, just that the total sum of minimum available ink should be more than 10**6
# and then print four ink values which are less than or equal to their corresponing min ink and sum upto 10**6

for tc in range(int(input())):
    printers = []
    for _ in range(3):
        printers.append(list(map(int, input().split())))
    mns = []
    for i in range(4):
        mn = 1000000
        for j in range(3):
            mn = min(mn, printers[j][i])
        mns.append(mn)
    print("Case #{}:".format(tc+1), end=" ")
    if sum(mns) < 1000000:
        print("IMPOSSIBLE")
    else:
        tot = 1000000
        for i in range(4):
            k = min(tot, mns[i])
            print(k, end=" ")
            tot -= k
        print()
