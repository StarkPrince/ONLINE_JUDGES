# https://www.codechef.com/START29B/problems/DCP

# store the initial value of each compound and then while they decompose keep adding them and when all those substance which can decompose ends, return the array of the final value of each compound

MOD = 10**9+7

n, m = map(int, input().split())
amount = list(map(int, input().split()))

compounds = {}
for i in range(m):
    ci, xi = map(int, input().split())
    deco_compounds = []
    sample = [int(x) for x in input().split()]
    for j in range(xi):
        deco_compounds.append((sample[2*j+1]-1, sample[2*j]))
    compounds[ci-1] = deco_compounds

bl = True
while(bl):
    bl = False
    for i in range(n):
        if(amount[i] == 0 or i not in compounds):
            continue
        else:
            deco_compounds = compounds[i]
            for compound in deco_compounds:
                amount[compound[0]] += (amount[i] * compound[1]) % MOD
            amount[i] = 0
            bl = True


for i in range(n):
    print(amount[i] % MOD)
