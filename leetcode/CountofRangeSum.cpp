// ?Problem : https://leetcode.com/problems/count-of-range-sum
// todo
// *Nice problem, all we have to do is to take mid and find the number of ranges in left and right of mid and then, there must me be an i and j for left and right of mid such that, sum[i,j] is in the range.

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
int mergeSort(vector<long> &sum, int lower, int upper, int low, int high)
{
    if (high - low <= 1)
        return 0;
    int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
    for (int i = low; i < mid; i++)
    {
        while (m < high && sum[m] - sum[i] < lower)
            m++;
        while (n < high && sum[n] - sum[i] <= upper)
            n++;
        count += n - m;
    }
    inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
    return count;
}

int countRangeSum(vector<int> &nums, int lower, int upper)
{
    int len = nums.size();
    vector<long> sum(len + 1, 0);
    for (int i = 0; i < len; i++)
        sum[i + 1] = sum[i] + nums[i];
    return mergeSort(sum, lower, upper, 0, len + 1);
}

void solve()
{
    int n, l, u;
    cin >> n >> l >> u;
    vector<int> v(n);
    cinv(v, n);
    print(countRangeSum(v, l, u));
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}