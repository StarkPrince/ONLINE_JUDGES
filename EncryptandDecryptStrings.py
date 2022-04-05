_end = '_end_'


def make_trie(*words):
    root = dict()
    for word in words:
        current_dict = root
        for letter in word:
            current_dict = current_dict.setdefault(letter, {})
        current_dict[_end] = _end
    return root


def find_in_trie(trie, word):
    current_dict = trie
    for letter in word:
        if letter in current_dict:
            current_dict = current_dict[letter]
        else:
            return False
    return True


class Encrypter:

    def __init__(self, keys, values, dictionary):
        self.dict = {}
        self.revDict = {}
        for i in range(len(keys)):
            self.dict[keys[i]] = values[i]
            if values[i] not in self.revDict:
                self.revDict[values[i]] = []
            self.revDict[values[i]].append(keys[i])
        self.comp = make_trie(*dictionary)
        return None

    def encrypt(self, word1):
        ans = ""
        for c in word1:
            ans += self.dict[c]
        return ans

    def decrypt(self, word2):
        ans = [""]
        for i in range(0, len(word2), 2):
            newAns = []
            for a in ans:
                if word2[i:i+2] not in self.revDict:
                    return 0
                for b in self.revDict[word2[i:i+2]]:
                    if find_in_trie(self.comp, a + b):
                        newAns.append(a + b)
            ans = newAns
        ctr = 0
        for i in ans:
            if find_in_trie(self.comp, i):
                ctr += 1
        return ctr


if __name__ == "__main__":
    enc = Encrypter(["a", "b", "c", "z"], ["aa", "bb", "cc", "zz"], [
                    "aa", "aaa", "aaaa", "aaaaa", "aaaaaaa"])
    print(enc.decrypt("aaaa"))
    print(enc.decrypt("aa"))
    print(enc.decrypt("aaaa"))
    print(enc.decrypt("aaaaaaaa"))
    print(enc.decrypt("aaaaaaaaaaaaaa"))
    print(enc.decrypt("aefagafvabfgshdthn"))

# 1,1,1,1,1,0
# 1,0,1,1,1,0
