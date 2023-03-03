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

// class Node:
//     def __init__(self, data):
//         self.data = data
//         self.children = set()
class Node
{
public:
    int data;
    set<Node *> children;
    Node(int data)
    {
        this->data = data;
        this->children = set<Node *>();
    }
};

pair<set<Node *>, int> getMax(Node *node, set<Node *> visited)
{
    if (node == NULL)
        return {visited, 0};
    if (visited.find(node) != visited.end())
        return {visited, 0};
    visited.insert(node);
    if (node->children.size() == 0)
        return {visited, node->data};
    int mn = node->data;
    int sm = node->data;
    for (auto child : node->children)
    {
        auto res = getMax(child, visited);
        visited = res.first;
        int points = res.second;
        mn = min(mn, points);
        sm += points;
    }
    sm -= mn;
    return {visited, sm};
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<Node *> nodes(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++)
    {
        int fun;
        cin >> fun;
        nodes[i] = new Node(fun);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
        if (order[i] != 0)
        {
            nodes[order[i] - 1]->children.insert(nodes[i]);
        }
    }
    set<Node *> visited;
    ll ans = 0;
    for (auto node : nodes)
    {
        auto res = getMax(node, visited);
        visited = res.first;
        int points = res.second;
        ans += points;
    }
    cout << "Case #" << tc + 1 << ": " << ans << endl;
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; i++)
        solve(i);
    return 0;
}