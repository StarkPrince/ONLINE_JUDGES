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

// def getMax(arr):
//     product = 1
//     for i in arr:
//         product *= i
//     if product > 0:
//         return [0, len(arr)-1, product]
//     lt = rt = 1
//     i = 0
//     while (lt > 0 and rt > 0):
//         lt *= arr[i]
//         i += 1
//     j = len(arr)-1
//     while (rt > 0 and j >= 0):
//         rt *= arr[j]
//         j -= 1
//     if abs(lt) >= abs(rt):
//         return [0, j, product//rt]
//     else:
//         return [i, len(arr)-1, product//lt]
vector<ll> getMax(vector<ll> arr)
{
    ll product = 1;
    for (auto i : arr)
        product *= i;
    if (product > 0)
        return {0, len(arr) - 1, product};
    ll lt = 1, rt = 1;
    ll i = 0, j = len(arr) - 1;
    while (lt > 0 and rt > 0)
    {
        lt *= arr[i];
        i += 1;
    }
    while (rt > 0 and j >= 0)
    {
        rt *= arr[j];
        j -= 1;
    }
    if (abs(lt) >= abs(rt))
        return {0, j, product / rt};
    else
        return {i, len(arr) - 1, product / lt};
}

// for _ in range(int(input())):
//     n = int(input())
//     v = [int(x) for x in input().split()]
//     s = []
//     temp = []
//     for i in range(n):
//         if v[i] != 0:
//             temp.append(v[i])
//         else:
//             s.append(temp)
//             temp = []
//     s.append(temp)
//     mx = 1
//     ans = [0, -1]
//     ctr = 0
//     for arr in s:
//         lt, rt, prod = getMax(arr)
//         if prod > mx:
//             ans = [ctr + lt, ctr + rt]
//             mx = max(prod, mx)
//         ctr += len(arr) + 1
//     print(ans[0], n-ans[1] - 1)

void solve()
{
    ll n, i = 0, mx = 1, ctr = 0;
    cin >> n;
    vector<ll> v(n), temp;
    cinv(v, n);
    pair<ll, ll> ans = {0, -1};
    vector<vector<ll>> s;
    while (i < n)
    {
        if (v[i] != 0)
            temp.pb(v[i]);
        else
        {
            s.pb(temp);
            temp.clear();
        }
        i++;
    }
    s.pb(temp);
    for (auto i : s)
    {
        vector<ll> temp = getMax(i);
        ll lt = temp[0], rt = temp[1], prod = temp[2];
        if (prod > mx)
        {
            ans.first = ctr + lt;
            ans.second = ctr + rt;
            mx = prod;
        }
        ctr += len(i) + 1;
    }
    cout << ans.first << " " << n - ans.second - 1 << endl;
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}