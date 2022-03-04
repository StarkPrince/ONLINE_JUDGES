
ans = 0
for word in words:
    if len(word) >= len(pref) and word[0:len(pref)] == pref:
        ans += 1
print(ans)

"prince"[:2] = "pr"
