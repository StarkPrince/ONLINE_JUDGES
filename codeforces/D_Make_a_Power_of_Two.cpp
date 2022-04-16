// ?Problem: https://codeforces.com/contest/1560/problem/D
// *Solution: just iterate for every power of two what is the least common substring and then return the changes required to make the string a power of two.
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

int calc(string t, string s)
{
    int n = s.size(), m = t.size();
    int idx = 0;
    for (int i = 0; i < n && idx < m; ++i)
        if (s[i] == t[idx])
            idx++;
    return (n - idx + m - idx);
}

void solve()
{
    string s;
    cin >> s;
    int ans = 2e9;
    for (long long i = 1ll; i <= 4e18; i *= 2ll)
    {
        int idx = 0;
        string t = to_string(i);
        int n = s.size(), m = t.size();
        for (int i = 0; i < n && idx < m; ++i)
            if (s[i] == t[idx])
                idx++;
        ans = min(ans, (n + m - 2 * idx));
    }
    cout << ans << endl;
}

int32_t main()
{
    ll tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}