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

// int deepestLeavesSum(TreeNode *root)
// {
//     queue<int> q;
//     vector<vector<int>> v;
//     q.push(root->val);
//     while (!q.empty())
//     {
//         int n = q.size();
//         vector<int> level;
//         while (n--)
//         {
//             TreeNode *t = q.front();
//             q.pop();
//             level.push_back(t->val);
//             if (t->left)
//                 q.push(t->left);
//             if (t->right)
//                 q.push(t->right);
//         }
//         v.push_back(level);
//     }
//     pv(v[v.size() - 1]);
// }

int largestCombination(vector<int> &candidates)
{
    vector<int> v(32);
    for (int i : candidates)
    {
        // increase the count of each bit
        for (int j = 31; j >= 0; j--)
        {
            if (i & (1 << j))
                v[j]++;
        }
    }
    sort(v.begin(), v.end());
    int mx = 0;
    for (int i = 0; i < 32; i++)
        mx = max(mx, v[i]);
    return mx;
}

int maxConsecutive(int bottom, int top, vector<int> &special)
{
    sort(special.begin(), special.end());
    int mx = 0;
    int ctr = 0;
    while (top > bottom)
    {
        int lo = bottom;
        int hi = min(special[ctr], top);
        int mx = max(mx, hi - lo);
        bottom = hi;
        ctr++;
    }
    return mx;
}

void solve()
{
    int top, bottom, n;
    cin >> top >> bottom >> n;
    vector<int> special(n);
    cinv(special, n);
    cout << maxConsecutive(bottom, top, special) << endl;
}

signed main()
{
    fast_io;
    pre();
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}