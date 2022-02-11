for _ in range(int(input())):
    hc, dc = map(int, input().split())
    hm, dm = map(int, input().split())
    k, w, a = map(int, input().split())
    bl = False
    for i in range(k+1):
        if (hm + dc + (k - i) * w - 1) // (dc + (k - i) * w) <= (hc + i * a + dm - 1) // dm:
            bl = True
            break
    print('YES' if bl else 'NO')
