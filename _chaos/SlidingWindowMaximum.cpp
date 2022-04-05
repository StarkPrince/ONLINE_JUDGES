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
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    cinv(nums, n);
    // multiset<ll> s;
    // for (int i = 0; i < k; i++)
    //     s.insert(a[i]);
    // // print max element of multiset s
    // for (int i = 0; i < n - k; i++)
    // {
    //     cout << *s.rbegin() << ' ';
    //     s.erase(s.find(a[i]));
    //     s.insert(a[i + k]);
    // }
    // cout << *s.rbegin() << endl;
    vector<int> res;

    int left[n];
    int right[n];

    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
            left[i] = nums[i];
        else
            left[i] = max(nums[i], left[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (i % k == 0)
            right[i] = nums[i];
        else
            right[i] = max(nums[i], right[i + 1]);
    }
    // print left array
    for (int i = 0; i < n; i++)
        cout << left[i] << ' ';
    cout << endl;
    // print right array
    for (int i = 0; i < n; i++)
        cout << right[i] << ' ';
    cout << endl;
    // for (int i = 0; i <= n - k; i++)
    //     res.push_back(max(right[i], left[i + k - 1]));
    // return res;
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}