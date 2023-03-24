// ?Problem : https://cses.fi/problemset/task/1755
// *Solution : we can use a map to store the frequency of each character and then we can check if the number of odd frequency characters is greater than 1 or not if it is greater than 1 then we can't make a palindrome out of it else we can make a palindrome out of it by using the characters with odd frequency and the characters with even frequency

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
    string s;
    cin >> s;
    int n = len(s);
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    int odd = 0;
    char odd_char;
    for (auto i : mp)
    {
        if (i.second % 2)
        {
            odd++;
            odd_char = i.first;
        }
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    string ans = "";
    for (auto i : mp)
    {
        if (i.second % 2 == 0)
        {
            for (int j = 0; j < i.second / 2; j++)
            {
                ans += i.first;
            }
        }
    }
    string ans2 = ans;
    reverse(all(ans2));
    if (odd)
    {
        for (int i = 0; i < mp[odd_char]; i++)
        {
            ans += odd_char;
        }
    }
    ans += ans2;
    cout << ans << endl;
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