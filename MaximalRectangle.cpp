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

int largestRectangleArea(vector<int> &height)
{
    int n = height.size();
    stack<int> s;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int h = (i == n ? 0 : height[i]);
        while (!s.empty() && height[s.top()] >= h)
        {
            int t = s.top();
            s.pop();
            int w = i - (s.empty() ? 0 : s.top() + 1);
            ans = max(ans, height[t] * w);
        }
        s.push(i);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j]++;
        }
        int area = largestRectangleArea(heights);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

void solve()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix) << endl;
}

int32_t main()
{

    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}