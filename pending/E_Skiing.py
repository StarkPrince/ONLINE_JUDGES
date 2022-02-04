from pip import main


class Graph:
    def __init__(self, n) -> None:
        self.n = n
        self.adj = [[-1 for _ in range(n+1)] for _ in range(n+1)]

    def add_edge(self, u, v, hu, hv):
        if hu < hv:
            self.adj[u][v] = 2*(hu-hv)
            self.adj[v][u] = hv-hu
        else:
            self.adj[u][v] = hv-hu
            self.adj[v][u] = 2*(hu-hv)


n, m = [int(x) for x in input().split()]
g = Graph(n)
weight = [int(x) for x in input().split()]
for i in range(m):
    u, v = [int(x) for x in input().split()]
    print(u, v)
    g.add_edge(u, v, weight[u-1], weight[v-1])
for i in g.adj:
    print(*i)
