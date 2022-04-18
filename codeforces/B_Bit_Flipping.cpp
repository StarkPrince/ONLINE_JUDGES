// ?Problem : https://codeforces.com/contest/1659/problem/1
// *Solution : if k is odd, get the first 1 and flip the bits around it and if no 1 is found, flip the bit at the end. then even no of moves are remaining, so count no of zeros in it and if zeros are less than k, take two zeros and replace them with 1 in two moves so in even no of moves, convert even no of zeros to 1. now if there is a zero left we can send it to the end and if there are 2 moves left, if no moves are left, return else return the string of all 1 and last index as zero.

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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        v.pb(s[i] - '0');
    if (k % 2 == 1)
    {
        int i = 0;
        while (i < n - 1 && s[i] != '1')
            i++;
        for (int j = 0; j < n; j++)
            if (j != i)
                v[j] = 1 ^ v[j];
        ans[i] = 1;
    }
    if (k % 2 == 1)
        k -= 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == 0)
            cnt += 1;
    int mt = min(k, cnt);
    if (mt % 2 == 1)
        mt -= 1;
    int tm = mt;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0 && mt > 0)
        {
            v[i] = 1;
            mt -= 1;
            ans[i] += 1;
        }
    }
    int lt = k - tm;
    if (k > cnt && cnt % 2 == 1 && lt > 1)
    {
        lt -= 2;
        int i = 0;
        while (i < n - 1 && v[i] != 0)
            i++;
        ans[i] += 1;
        ans[n - 1] += 1;
        for (int i = 0; i < n - 1; i++)
            v[i] = 1;
        v[n - 1] = 0;
    }
    ans[0] += lt;
    for (int i = 0; i < n; i++)
        cout << v[i];
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}