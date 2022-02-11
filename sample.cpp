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

int computeDeviceCrossovers(int n, vector<int> websiteVisits, int m, vector<int> appVisits)
{
    // Write your code here
    vector<int> mediumOfVisit(10005);
    for (int i : websiteVisits)
    {
        mediumOfVisit[i] = 1;
    }
    for (int i : appVisits)
    {
        mediumOfVisit[i] = -1;
    }
    int contextSwitches = 0, lastDevice = 0;
    for (int i = 0; i < 10005; i++)
    {
        if (mediumOfVisit[i] == 1 || mediumOfVisit[i] == -1)
        {
            if (lastDevice == 0)
            {
                lastDevice = mediumOfVisit[i];
            }
            else if (lastDevice != mediumOfVisit[i])
            {
                contextSwitches++;
                lastDevice = mediumOfVisit[i];
            }
        }
    }
    return contextSwitches;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> websiteVisits(n);
    cinv(websiteVisits, n);
    vector<int> appVisits(m);
    cinv(appVisits, m);
    cout << computeDeviceCrossovers(n, websiteVisits, m, appVisits) << endl;
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