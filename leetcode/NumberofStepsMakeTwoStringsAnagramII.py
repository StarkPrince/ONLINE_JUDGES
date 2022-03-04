# https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
# easy peasy solution just store the count of each char in a hashmap
# then iterate through the hashmap and get the min of the count
# that min will be in both and we have to delete the rest

s = "leetcode"
t = "coats"

s_dict = {}
t_dict = {}

for i in s:
    if i not in s_dict:
        s_dict[i] = 0
    s_dict[i] += 1

for i in t:
    if i not in t_dict:
        t_dict[i] = 0
    t_dict[i] += 1

common = 0
for i in s_dict:
    if i in t_dict:
        common += min(s_dict[i], t_dict[i])

print(len(s)+len(t) - 2 * common)
