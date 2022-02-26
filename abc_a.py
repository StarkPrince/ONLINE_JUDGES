# a = [int(x) for x in input().split()]
# print(a[a[a[0]]])
n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

 da = {}
  db = {}
   for i in a:
        if i not in da:
            da[i] = 0
        da[i] += 1

    for i in b:
        if i not in db:
            db[i] = 0
        db[i] += 1

    bl = True
    for i, j in db.items():
        if i not in da or da[i] < j:
            bl = False
            break

    print('Yes' if bl else 'No')
