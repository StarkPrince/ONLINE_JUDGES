#include <bits/stdc++.h>
#define int long long
#define inf 10000000000000
using namespace std;
int ans, n, m, h[200005], dis[200005];
vector<int> e[200005];
queue<int> q;
signed main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i]), dis[i] = -inf;
    for (int i = 1, j, k; i <= m; i++)
    {
        scanf("%lld %lld", &j, &k);
        e[j].push_back(k);
        e[k].push_back(j);
    }
    q.push(1);
    dis[1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++)
        {
            int t = h[x] - h[e[x][i]];
            if (t < 0)
                t = t + t;
            if (dis[e[x][i]] < dis[x] + t)
            {
                dis[e[x][i]] = dis[x] + t;
                ans = max(ans, dis[e[x][i]]);
                q.push(e[x][i]);
            }
        }
    }
    cout << ans;
    return 0;
}