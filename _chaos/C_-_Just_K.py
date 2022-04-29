import itertools

n,k = [int(x) for x in input().split()]
d = {chr(i):set() for i in range(97,123)}
for i in range(n):
    s = input()
    for j in range(len(s)):
        d[s[j]].add(i)
ans = 0
vectors = [[]]
for i in range(n):
    newVect = []
    for j in vectors:
        newVect.append(j+[i])
        newVect.append(j)
    vectors = newVect
ans = 0
for vect in vectors:
    temp = 0
    st = set(vect)
    for i in range(97,123):
        ts = st.copy()
        ts.intersection_update(d[chr(i)])
        if len(ts)==k:
            temp += 1
    ans = max(ans,temp)
print(ans)