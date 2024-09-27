#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
    vector<double> probab(n, 0);
    set<pair<double, int>> st;

    st.insert({(double)1, start_node});
    probab[start_node] = 1;

    while (!st.empty())
    {
        auto it = st.begin();
        double prob = it->first;
        int node = it->second;
        st.erase(it);

        for (int i = 0; i < edges.size(); i++)
        {
            int start = edges[i][0];
            int end = edges[i][1];
            double edgeprob = succProb[i];

            if (node == start && probab[end] < prob * edgeprob)
            {
                auto f = st.find({probab[end], end});
                if (f != st.end())
                {
                    st.erase(f);
                }

                probab[end] = prob * edgeprob;
                st.insert({probab[end], end});
            }
        }
    }

    return probab[end_node];
}

int main()
{
    int n = 5;
    vector<vector<int>> edges;
    edges.push_back({1, 4});
    edges.push_back({2, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 3});
    edges.push_back({0, 2});
    edges.push_back({2, 3});

    vector<double> succProb = [ 0.37, 0.17, 0.93, 0.23, 0.39, 0.04 ];

    int start_node = 3;
    int end_node = 4;

    cout << maxProbability(n, edges, succProb, start_node, end_node) << endl;
}