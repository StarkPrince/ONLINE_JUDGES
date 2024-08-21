#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // Add v to u's list
        adj[v].push_back(u); // Add u to v's list for an undirected graph
    }

    void dijkstra(int src)
    {
        vector<int> visted(V + 1);
        set<pair<int, int>> st;
    }
}