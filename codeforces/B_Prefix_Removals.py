# https://codeforces.com/contest/1654/problem/B
# i am dumb
# we have to keep removing the prefixes until we get a string that is not a prefix of any other string
# hint: check for characters in the string


for _ in range(int(input())):
    word = input()
    d = {}
    for i in range(len(word)):
        if word[i] not in d:
            d[word[i]] = set()
        d[word[i]].add(i)
    i = 0
    while i < len(word):
        if len(d[word[i]]) > 1:
            d[word[i]].remove(i)
        else:
            break
        i += 1
    print(word[i:])
