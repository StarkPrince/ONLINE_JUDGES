#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////
/*
██████╗░██████╗░██╗███╗░░██╗░█████╗░███████╗  ██████╗░░█████╗░░░░░░██╗
██╔══██╗██╔══██╗██║████╗░██║██╔══██╗██╔════╝  ██╔══██╗██╔══██╗░░░░░██║
██████╔╝██████╔╝██║██╔██╗██║██║░░╚═╝█████╗░░  ██████╔╝███████║░░░░░██║
██╔═══╝░██╔══██╗██║██║╚████║██║░░██╗██╔══╝░░  ██╔══██╗██╔══██║██╗░░██║
██║░░░░░██║░░██║██║██║░╚███║╚█████╔╝███████╗  ██║░░██║██║░░██║╚█████╔╝
╚═╝░░░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚════╝░╚══════╝  ╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░
*/
///////////////////////////////////////////////////
#define fast_io                            \
    ios::sync_with_stdio(false);           \
    cin.tie(0);                            \
    cout.tie(0);                           \
#define file_io                        \
        freopen('input.txt', 'r+', stdin); \
    freopen('output.txt', 'w+', stdout);

///////////////////////////////////////////////////
#define pv(v)             \
    for (auto i : v)      \
        cout << i << ' '; \
    cout << endl;
#define cinv(v, n)              \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
//////////////////////////////////////////////////
typedef long long ll;
#define int long long
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define minf -0x3f3f3f3f

///////////////////////////////////////////////////
#define mem(a, t) memset(a, t, sizeof(a))
#define endl '\n'
#define print(x) cout << x << endl

///////////////////////////////////////////////////
#define pb push_back
#define Pb pop_back
#define be() begin()
#define en() end()
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define len(p) (ll) p.size()

///////////////////////////////////////////////////

ll handle_mod(ll n, ll mod = MOD)
{
    return (n < 0 ? mod - abs(n % mod) : n) % mod;
}

ll binpow(ll a, ll b, ll m = 1e18)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

struct dijkstra
{
    int n;
    vector<ll> dists;
    vector<int> par;
    vector<bool> vis;
    vector<vector<pair<ll, int>>> edges;

    void init(int n)
    {
        dists = vector<ll>(n);
        vis = vector<bool>(n);
        par = vector<int>(n);
        edges = vector<vector<pair<ll, int>>>(n);
    }

    void edge(int a, int b, ll wt)
    {
        edges[a].push_back(make_pair(wt, b));
        edges[b].push_back(make_pair(wt, a));
    }

    using ptype = pair<ll, int>;
    void run(int src)
    {
        fill(dists.begin(), dists.end(), inf);
        fill(vis.begin(), vis.end(), false);
        fill(par.begin(), par.end(), -1);

        priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
        dists[src] = 0;
        pq.push(make_pair(0, src));
        while (!pq.empty())
        {
            ptype foc = pq.top();
            pq.pop();

            if (vis[foc.second])
                continue;
            vis[foc.second] = 1;

            dists[foc.second] = min(dists[foc.second], foc.first);
            for (ptype x : edges[foc.second])
            {
                ll d = dists[foc.second] + x.first;
                if (d < dists[x.second])
                {
                    dists[x.second] = d;
                    par[x.second] = foc.second;
                    pq.push(make_pair(d, x.second));
                }
            }
        }
    }
};

void solve()
{
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}