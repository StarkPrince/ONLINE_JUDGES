// https://www.codechef.com/START29B/problems/CCD
// store the prefix sum of alternating element and then if the difference between the sum of the ranges in s and t is multiplication of zero return Yes else return No

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
    ll n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<int> apsei(n + 1, 0);
    vector<int> apsoi(n + 1, 0);
    vector<int> bpsei(n + 1, 0);
    vector<int> bpsoi(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (i == 0)
            {
                apsei[i] = a[i - 1] - 'a';
                bpsei[i] = b[i - 1] - 'a';
            }
            else
            {
                apsoi[i] = apsoi[i - 1];
                bpsoi[i] = bpsoi[i - 1];
                apsei[i] = apsei[i - 2] + (a[i - 1] - 'a');
                bpsei[i] = bpsei[i - 2] + (b[i - 1] - 'a');
            }
        }
        else
        {
            if (i == 1)
            {
                apsoi[i] = a[i - 1] - 'a';
                bpsoi[i] = b[i - 1] - 'a';
            }
            else
            {
                apsei[i] = apsei[i - 1];
                bpsei[i] = bpsei[i - 1];
                apsoi[i] = apsoi[i - 2] + (a[i - 1] - 'a');
                bpsoi[i] = bpsoi[i - 2] + (b[i - 1] - 'a');
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        ll uei, uoi, dei, doi;
        uei = handle_mod(bpsei[r] - apsei[r]);
        dei = handle_mod(bpsei[l - 1] - apsei[l - 1]);
        uoi = handle_mod(bpsoi[r] - apsoi[r]);
        doi = handle_mod(bpsoi[l - 1] - apsoi[l - 1]);
        ll sei = uei - dei;
        ll soi = uoi - doi;
        if ((sei - soi) % 26 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
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