import time


def countMismatchedPayments(n, accountNames, dues, m, accountsPayingByCheques, chequeAmounts):
    accountDues = {}
    for accountIndex in range(n):
        accountDues[accountNames[accountIndex]] = dues[accountIndex]
    mismatchedPayments = 0
    for accountIndex in range(m):
        if accountDues[accountsPayingByCheques[accountIndex]] != chequeAmounts[accountIndex]:
            mismatchedPayments += 1
    return mismatchedPayments


start = time.time()
n = int(input())
accountName = [i for i in range(n)]
dues = [i for i in range(n)]
m = int(input())
accountsPayingByCheques = [i for i in range(m)]
chequeAmounts = [n-i for i in range(m)]
print(countMismatchedPayments(n, accountName, dues,
      m, accountsPayingByCheques, chequeAmounts))
print(time.time() - start)
