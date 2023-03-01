n,w = [int(i) for i in input().split()]
a  = [int(i) for i in input().split()]
a.sort()
st = set()
for i in range(n):
    if a[i] < w:
        st.add(a[i])
for i in range(len(a)):
    for j in range(i+1,len(a)):
        if a[i]+a[j] <= w:
            st.add(a[i]+a[j])
        else:
            break
for i in range(len(a)):
    for j in range(i+1,len(a)):
        for k in range(j+1,len(a)):
            if (a[i]+a[j]+a[k])<=w:
                st.add(a[i]+a[j]+a[k])
            else:
                break
ans = 0
for i in st:
    if i <= w:
        ans += 1
print(ans)