# a = input()
# for i in range(6//len(a)):
#     print(a,end="")

# Find the minimum number of minutes need to pass to reach palindromic time.

def time_difference(time_stamp,a):
    tm = int(a)*60+int(a[::-1])
    if tm>=time_stamp:
        return tm-time_stamp
    return tm + 24*60 - time_stamp

def paindromic_time(A):
    palindromic_times = []
    for i in range(24):
        for j in range(60):
            i = str(i).zfill(2)
            j = str(j).zfill(2)
            if i == j[::-1]:
                palindromic_times.append(i)
    a,b = A.split(":")
    time_stamp = int(a)*60+int(b)
    min_diff = 24*60
    for i in palindromic_times:
        diff = time_difference(time_stamp,i)
        if diff<min_diff:
            min_diff = diff
    return min_diff

print(paindromic_time("05:51"))