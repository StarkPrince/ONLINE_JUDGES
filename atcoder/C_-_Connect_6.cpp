// https://atcoder.jp/contests/abc241/tasks/abc241_c
//  easy peasy question to do with, just iterate horizontally, vertically, top left to bottom right, top right to bottom left
//  and check if the number of #s is greater than equal to 4 in a segment of 6 if yes, return Yes else after iterating through all the segments return No

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
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

void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        vector<char> v(n);
        cinv(v, n);
        s[i] = v;
    }
    ll ans = 0;

    // check horizontallly
    for (int i = 0; i < n - 5 && ans == 0; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            for (int k = 0; k < 6; k++)
            {
                if (s[j][i + k] == '#')
                    temp++;
            }
            if (temp >= 4)
                ans++;
        }
    }
    // check vertically
    for (int i = 0; i < n - 5 && ans == 0; i++)
    {
        for (int j = 0; j < n && ans == 0; j++)
        {
            int temp = 0;
            for (int k = 0; k < 6; k++)
            {
                if (s[i + k][j] == '#')
                    temp++;
            }
            if (temp >= 4)
                ans++;
        }
    }
    // check top left to bottom right
    for (int i = 0; i < n - 5 && ans == 0; i++)
    {
        for (int j = 0; j < n - 5 && ans == 0; j++)
        {
            int temp = 0;
            for (int k = 0; k < 6; k++)
            {
                if (s[i + k][j + k] == '#')
                    temp++;
            }
            if (temp >= 4)
                ans++;
        }
    }
    // check top right to bottom left
    for (int i = 0; i < n - 5 && ans == 0; i++)
    {
        for (int j = n - 1; j >= 5 && ans == 0; j--)
        {
            int temp = 0;
            for (int k = 0; k < 6; k++)
            {
                if (s[i + k][j - k] == '#')
                    temp++;
            }
            if (temp >= 4)
                ans++;
        }
    }

    if (ans == 0)
        print("No");
    else
        print("Yes");
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}