//?Problem: https://codeforces.com/contest/788/problem/A
// *Solution: First we have to get the abs diff array and then we have to calculate the max range sum by getting prefix sums on odd indices and even indices.
// *Post-Condition: get the differnce of adjacent elements and then get the max sum of the range.

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

void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v(n - 1), even(1), odd(1), diff(n + 1);
    cinv(v1, n);
    for (int i = 0; i < n - 1; i++)
        v[i] = abs(v1[i + 1] - v1[i]);
    n -= 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even.pb(even[even.size() - 1] + v[i]);
            odd.pb(odd[odd.size() - 1]);
        }
        else
        {
            odd.pb(odd[odd.size() - 1] + v[i]);
            even.pb(even[even.size() - 1]);
        }
    }
    int ans = 0, mx = -inf, mn = inf;
    for (int i = 0; i <= n; i++)
    {
        diff[i] = even[i] - odd[i];
        mx = max(mx, diff[i]);
        ans = max(ans, mx - mn);
        mn = min(mn, diff[i]);
    }
    ans = max(ans, mx - mn);
    cout << ans << endl;
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}