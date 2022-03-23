// ?Problem : https://codeforces.com/contest/1657/problem/C
// *soln :  there can be four type of sequence in first 2 characters, ((, (), )) and )(, for the first three case increase i by 2 and just else increase i till a[i]!=")" again which will make the sequence a palindrome and thus we can increase i to that number and if for the whole traversal you didnt found any palindrom or RBS, return the length of the string - catched(i)

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
    ll a, temp;
    string b;
    cin >> a >> b;
    ll operations = 0;
    ll i = 0;
    bool bl = true;
    while (i < a - 1)
    {
        if (b[i] == '(' or (b[i] == ')' and b[i + 1] == ')'))
        {
            operations += 1;
            i += 2;
        }
        else
        {
            temp = i;
            i += 1;
            while (b[i] == '(' and i < a - 1)
                i += 1;
            if (b[i] == ')')
            {
                operations += 1;
                i += 1;
            }
            else
                bl = false;
        }
    }
    if (bl)
        cout << operations << " " << a - i << endl;
    else
        cout << operations << " " << a - temp << endl;
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}