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

int minTimeToFinish(priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq, int changeTime, int numLaps)
{
    if (numLaps == 0)
        return 0;
    int time = inf;
    // create tq which is a clone of pq
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> tq = pq;

    vector<int> p = pq.top();
    vector<int> t = tq.top();
    pq.pop();
    tq.pop();

    // case 1 : change the tyre of the fastest car and race it
    t[0] = t[2];
    tq.push(t);
    time = min(time, changeTime + t[0] + minTimeToFinish(tq, changeTime, numLaps - 1));

    // case 2 : dont change the tyre but race the fastest car
    p[0] *= p[1];
    pq.push(p);
    time = min(time, p[0] + minTimeToFinish(pq, changeTime, numLaps - 1));

    return time;
}

void solve()
{
    ll n, changeTime, numLaps;
    cin >> n >> changeTime >> numLaps;
    vector<vector<int>> tires;
    for (int i = 0; i < n; i++)
    {
        int a, r;
        cin >> a >> r;
        tires.pb({a, r, a});
    }
    // create a minheap of the tires sorted by the time when they will be finished
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (auto tire : tires)
        pq.push(tire);

    print(minTimeToFinish(pq, changeTime, numLaps));
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