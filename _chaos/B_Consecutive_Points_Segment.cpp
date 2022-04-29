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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vect(n);
    cinv(vect, n);
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] == vect[i - 1] + 1 || vect[i] == vect[i - 1] || vect[i] == vect[i - 1] + 2)
        {
            vect[i] = vect[i - 1] + 1;
            cnt++;
        }
        else
            break;
    }
    if (cnt == n)
    {
        cout << "YES" << endl;
        return;
    }
    cnt = 1;
    vect[0] += 1;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] == vect[i - 1] + 1 || vect[i] == vect[i - 1] || vect[i] == vect[i - 1] + 2)
        {
            vect[i] = vect[i - 1] + 1;
            cnt++;
        }
        else
            break;
    }
    if (cnt == n)
    {
        cout << "YES" << endl;
        return;
    }
    cnt = 1;
    vect[0] -= 2;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] == vect[i - 1] + 1 || vect[i] == vect[i - 1] || vect[i] == vect[i - 1] + 2)
        {
            vect[i] = v[i - 1] + 1;
            cnt++;
        }
        else
            break;
    }
    if (cnt == n)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
    return;
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