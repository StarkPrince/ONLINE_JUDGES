n = int(input())
st = set()
tr = []
for i in range(n):
    a,b = input().split()
    if a not in st:
        st.add(a)
        tr.append([int(b),i+1])
tr = sorted(tr,key=lambda x:(-x[0],x[1]))
print(tr[0][1])