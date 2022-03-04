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

vector<ll> coins = {1, 2, 4, 6, 8, 16, 24, 32, 64, 120, 128, 256, 512, 720, 1024, 2048, 4096, 5040, 8192, 16384, 32768, 40320, 65536, 131072, 262144, 362880, 524288, 1048576, 2097152, 3628800, 4194304, 8388608, 16777216, 33554432, 39916800, 67108864, 134217728, 268435456, 479001600, 536870912, 1073741824, 2147483648, 4294967296, 6227020800, 8589934592, 17179869184, 34359738368, 68719476736, 87178291200, 137438953472, 274877906944, 549755813888};

ll coinChange(ll amount, vector<ll> &coins, ll idx, unordered_map<string, ll> &d)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return 10e13;
    if (idx >= coins.size())
        return 10e13;
    string st = to_string(amount) + " " + to_string(coins[idx]);
    if (d.find(st) == d.end())
    {
        d[st] = min(1 + coinChange(amount - coins[idx], coins,
                                   idx + 1, d),
                    coinChange(amount, coins, idx + 1, d));
    }
    return d[st];
}

void solve()
{
    ll n;
    cin >> n;
    unordered_map<string, ll> d;
    ll ans = coinChange(n, coins, 0, d);
    if (ans == 10e13)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
