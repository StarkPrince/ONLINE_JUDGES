// ?Problem :
// *Solution :

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
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);                 \
    cout << fixed << setprecision(9);
///////////////////////////////////////////////////
#define pv(v)             \
    for (auto i : v)      \
        cout << i << ' '; \
    cout << endl;
#define cinv(v, n)              \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
//////////////////////////////////////////////////
const int maxN = 200005;
typedef long long ll;
#define int long long
#define MOD 1000000007
#define inf 0x3f3f3f3f

///////////////////////////////////////////////////
#define mem(a, t) memset(a, t, sizeof(a))
#define endl '\n'
template <typename T>
void print(T &&t)
{
    cout << t << '\n';
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
    cout << t << ' ';
    print(forward<Args>(args)...);
}

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

void pre()
{
    return;
}

class SegmentTree
{
public:
    vector<pair<int, int>> tree;
    int n;
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = {arr[start], arr[start]};
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node].first = min(tree[2 * node + 1].first, tree[2 * node + 2].first);
            tree[node].second = max(tree[2 * node + 1].second, tree[2 * node + 2].second);
        }
    }
    int query_min(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return inf;
        if (l <= start && end <= r)
            return tree[node].first;
        int mid = (start + end) / 2;
        int left = query_min(2 * node + 1, start, mid, l, r);
        int right = query_min(2 * node + 2, mid + 1, end, l, r);
        return min(left, right);
    }
    int query_max(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return -inf;
        if (l <= start && end <= r)
            return tree[node].second;
        int mid = (start + end) / 2;
        int left = query_max(2 * node + 1, start, mid, l, r);
        int right = query_max(2 * node + 2, mid + 1, end, l, r);
        return max(left, right);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    SegmentTree tree(arr);
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (arr[l] == tree.query_min(0, 0, n - 1, l, r) || arr[l] == tree.query_max(0, 0, n - 1, l, r))
            l++;
        else if (arr[r] == tree.query_min(0, 0, n - 1, l, r) || arr[r] == tree.query_max(0, 0, n - 1, l, r))
            r--;
        else
            break;
    }
    if (l >= r)
        cout << -1 << endl;
    else
        cout << l + 1 << " " << r + 1 << endl;
}

signed main()
{
    fast_io;
    pre();
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}