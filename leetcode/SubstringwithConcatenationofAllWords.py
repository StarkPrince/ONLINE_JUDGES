def findSubstring(s, words):
    m = len(s)
    t = [0]*(m+1)
    mod = 10**9+7
    lnt = len(words)*len(words[0])

    for i in range(m):
        t[i+1] = (t[i]*127+ord(s[i]))%mod

    mt = 0
    for word in words:
        for ch in word:
            mt = (mt*127+ord(ch))%mod
            print(mt, end=" ")
    print()

    for i in range(m-lnt):
        print((t[i+lnt]-t[i])%mod,end=" ")
    return []

s = "barfoothefoobarman"

words = ["foo","bar"]

print(findSubstring(s,words))
