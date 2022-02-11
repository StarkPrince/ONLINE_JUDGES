class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


n = int(input())
s = Node(0)
root = s
a = list(input())
for i in range(len(a)):
    nw = Node(i + 1)
    # "something<->s<->something_else"
    # something.right = nw
    # nw.left = something
    # s.left = nw
    # nw.right = s
    # s = nw
    if a[i] == "L":
        if s.left:
            s.left.right = nw
            nw.left = s.left
            s.left = nw
            nw.right = s
        else:
            nw.right = s
            s.left = nw
        s = nw

    # "something<->s<->something_else"
    # something_else.left = nw
    # nw.right = something_else
    # s.right = nw
    # nw.left = s
    # s = nw
    else:
        if s.right:
            s.right.left = nw
            nw.right = s.right
            s.right = nw
            nw.left = s
        else:
            nw.left = s
            s.right = nw
        s = nw

while(root.left):
    root = root.left
while(root):
    print(root.data, end=" ")
    root = root.right
