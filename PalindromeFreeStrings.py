def palindrome(string):
    return string == string[::-1]


def perfect_string(string):
    for i in range(len(string)):
        for j in range(i+5, len(string)):
            if palindrome(string[i:j+1]):
                return False
    return True


def rec(string, index, word):
    if index == len(string):
        return [word]
    if string[index] == "?":
        return rec(string, index+1, word+"1") + rec(string, index+1, word+"0")
    else:
        return rec(string, index+1, word+string[index])


for tc in range(int(input())):
    a = int(input())
    b = input()
    strings = rec(b, 0, "")
    for string in strings:
        if perfect_string(string):
            print("Case #{}: {}".format(tc+1, "POSSIBLE"))
            break
    else:
        print("Case #{}: {}".format(tc+1, "IMPOSSIBLE"))
