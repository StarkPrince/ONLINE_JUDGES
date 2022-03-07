// https://www.codechef.com/COOK139B/problems/ALTERNATEDIV
//  I was dumb not to notice that the elements were repeating in my sequence
//  Soln: for even indices print i+1 and for odd print double of previous one

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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            a[i] = i + 1;
        else
            a[i] = 2 * a[i - 1];
    }
    pv(a);
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
// https://codeforces.com/gym/103185/problem/G
// https://codeforces.com/contest/154/problem/A
// https://codeforces.com/contest/474/problem/D
// https://codeforces.com/contest/339/problem/D
// https://codeforces.com/contest/1548/problem/B
// https://codeforces.com/contest/1545/problem/C
// https://codeforces.com/contest/1545/problem/D
// https://codeforces.com/contest/1508/problem/D
// https://codeforces.com/contest/1482/problem/D
// https://codeforces.com/contest/1609/problem/D
// https://codeforces.com/contest/1552/problem/D
// https://codeforces.com/contest/1589/problem/D
// https://codeforces.com/contest/1586/problem/I
// https://codeforces.com/contest/1491/problem/I
// https://codeforces.com/contest/1553/problem/I
// https://codeforces.com/contest/1586/problem/F
// https://codeforces.com/contest/1586/problem/F
// https://codeforces.com/contest/1552/problem/H
// https://codeforces.com/contest/1548/problem/E
// https://codeforces.com/contest/1583/problem/F
// https://codeforces.com/contest/1552/problem/H
// https://codeforces.com/contest/1545/problem/F
// https://codeforces.com/contest/1552/problem/G
// https://codeforces.com/contest/1543/problem/E
// https://codeforces.com/contest/1503/problem/F
// https://codeforces.com/contest/1610/problem/F
// https://codeforces.com/contest/1562/problem/F
// https://codeforces.com/contest/1553/problem/H
// https://codeforces.com/contest/1552/problem/G
// https://codeforces.com/contest/1558/problem/F
// https://codeforces.com/contest/1612/problem/F
// https://codeforces.com/contest/1548/problem/E
// https://codeforces.com/contest/1530/problem/H
// https://codeforces.com/contest/1578/problem/H
// https://codeforces.com/contest/1610/problem/H
// https://codeforces.com/contest/1580/problem/F
// https://codeforces.com/contest/1553/problem/H
// https://codeforces.com/contest/1622/problem/F
// https://codeforces.com/contest/1578/problem/G
// https://codeforces.com/contest/1606/problem/F
// https://codeforces.com/contest/1605/problem/F
// https://codeforces.com/contest/1537/problem/F
// https://codeforces.com/contest/1355/problem/D