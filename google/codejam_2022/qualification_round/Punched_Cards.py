# Problem : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
# shitty pattern printing question


for tc in range(int(input())):
    print("Case #{}:".format(tc+1))
    r, c = [int(x) for x in input().split()]
    for i in range(r):
        if i == 0:
            print(".." + "+-"*(c-1)+"+")
            print(".." + "|."*(c-1)+"|")
        else:
            print("+-"*c+"+")
            print("|."*c+"|")
    print("+-"*c+"+")
