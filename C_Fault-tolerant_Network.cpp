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
#define inf 1e18
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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), sa(n), sb(n);
    cinv(a, n);
    cinv(b, n);
    // store store a in sa
    for (int i = 0; i < n; i++)
    {
        sa[i] = a[i];
        sb[i] = b[i];
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    ll mn = inf;
    // case 1 attach both the ends
    mn = min(mn, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    // case 2 attach the first end and find
    ll temp = inf, temp2 = inf;
    for (int i = 1; i < n - 1; i++)
    {
        int lo = lower_bound(sb.begin(), sb.end(), a[i]) - sb.begin();
        int up = upper_bound(sb.begin(), sb.end(), a[i]) - sb.begin();
        if (lo > 0)
            temp = min(temp, abs(a[i] - sb[lo - 1]) + abs(a[i] - sb[up]));
        if (up < n - 1)
            temp = min(temp, abs(a[i] - sb[lo]) + abs(a[i] - sb[up + 1]));
    }
    mn = min(mn, temp + min(abs(a[0] - b[0]), abs(a[n - 1] - b[n - 1])));
    for (int i = 1; i < n - 1; i++)
    {
        int lo = lower_bound(sa.begin(), sa.end(), b[i]) - sa.begin();
        int up = upper_bound(sa.begin(), sa.end(), b[i]) - sa.begin();
        if (lo > 0)
            temp2 = min(temp2, abs(b[i] - sa[lo - 1]) + abs(b[i] - sa[up]));
        if (up < n - 1)
            temp2 = min(temp2, abs(b[i] - sa[lo]) + abs(b[i] - sa[up + 1]));
    }
    mn = min(mn, temp + temp2);
    print(mn);
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
