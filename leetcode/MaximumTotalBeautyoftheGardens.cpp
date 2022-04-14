// ?Problem : https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/
// *Solution : Iterate through 1 to n and check how many if i gardens can be fully filled if yes, then divide the remaining flowers equally in the rest of the gardens else, break if flowers are less to fill i gardens.

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

long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
{
    sort(all(flowers));
    vector<int> ps(1);
    for (int &i : flowers)
    {
        i = min(i, target);
        ps.push_back(ps.back() + (int)i);
    }
    int ans = 0, n = flowers.size(), pc = n;
    for (int fc = 0; fc <= n; fc++)
    {
        int x = newFlowers - (target * fc - (ps[n] - ps[n - fc]));
        if (x < 0)
            break;
        for (pc = min(pc, n - fc); pc > 0 && flowers[pc - 1] * pc - ps[pc] > x; pc--)
            ;
        int pm = pc && flowers[0] < target ? min<int>(target - 1, (x + ps[pc]) / pc) : 0;
        ans = max(ans, fc * full + pm * partial);
    }
    return ans;
}

void solve()
{
    int n, target, full, partial;
    ll newFlowers;
    cin >> n >> newFlowers >> target >> full >> partial;
    vector<int> flowers(n);
    cinv(flowers, n);
    cout << maximumBeauty(flowers, newFlowers, target, full, partial) << endl;
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}