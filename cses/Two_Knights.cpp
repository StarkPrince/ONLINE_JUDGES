// ?Problem : https://cses.fi/problemset/task/1072
// *Solution : we have divided it into different groups on which how many ways we can place the knights and then we have to subtract the cases from the total cases

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

void solve(ll n)
{
    if (n == 1)
    {
        print(0);
    }
    else if (n == 2)
    {
        print(6);
    }
    else if (n == 3)
    {
        print(28);
    }
    else
    {
        ll vert = 4, d1ve1 = 0;
        ll d1ve = min(n - 2, 2ll) * 4;
        ll d2ve = max(0ll, n - 4) * 4;
        ll vert1 = min(1ll, n / 2 - 1) * 4;
        ll ns = n * n;
        if (n >= 5)
            d1ve1 = (n - 4) * 4;
        ll rest = n * n - (vert + d1ve + d2ve + vert1 + d1ve1);
        ll ans = ns * (ns - 1) - (vert * 2 + d1ve * 3 + d2ve * 4 + vert1 * 4 + d1ve1 * 6 + rest * 8);
        print(ans / 2);
    }
}

signed main()
{
    fast_io;
    pre();
    ll tc = 1;
    cin >> tc;
    ll n = 1;
    while (n <= tc)
    {
        solve(n);
        n++;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}