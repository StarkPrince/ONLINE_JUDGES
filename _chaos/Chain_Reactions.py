class Node:
    def __init__(self, data):
        self.data = data
        self.children = set()


def getMax(node, visited):
    if node in visited:
        return [visited, 0]
    visited.add(node)
    if len(node.children) == 0:
        return [visited, node.data]
    sm = node.data
    mn = node.data
    for child in node.children:
        visited, points = getMax(child, visited)
        mn = min(mn, points)
        sm += points
    sm -= mn
    return [visited, sm]


for tc in range(int(input())):
    n = int(input())
    nodes = [Node(int(x)) for x in input().split()]
    order = [int(x) for x in input().split()]
    for i in range(n):
        if order[i] != 0:
            nodes[order[i]-1].children.add(nodes[i])
    visited = set()
    ans = 0
    for node in nodes:
        visited, points = getMax(node, visited)
        ans += points
        i += 1
    print("Case #{}: {}".format(tc+1, ans))
