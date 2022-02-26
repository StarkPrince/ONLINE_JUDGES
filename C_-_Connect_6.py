n = int(input())
s = []
for i in range(n):
    s.append(list(input()))

# check vertically
for i in range(n-5):
    for j in range(n):
        if s[j][i:i+6].count("#") >= 4:
            print("Yes")
            exit()

        temp = 0
        for k in range(6):
            if s[j][i+k] == "#":
                temp += 1
        if temp >= 4:
            print("Yes")
            exit()

    for j in range(n-5):
        temp = 0
        for k in range(6):
            if s[j][i+k] == "#":
                temp += 1
        if temp >= 4:
            print("Yes")
            exit()

        temp = 0
        for k in range(6):
            if s[5+j][i+k] == "#":
                temp += 1
        if temp >= 4:
            print("Yes")
            exit()

print("No")
