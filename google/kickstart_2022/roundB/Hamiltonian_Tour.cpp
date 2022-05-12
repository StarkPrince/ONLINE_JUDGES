// ?Problem :
// *Solution :

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
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);                 \
    cout << fixed << setprecision(9);
///////////////////////////////////////////////////
#define pv(v)             \
    for (auto i : v)      \
        cout << i << ' '; \
    cout << endl;
#define cinv(v, n)              \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
//////////////////////////////////////////////////
const int maxN = 200005;
typedef long long ll;
#define int long long
#define MOD 1000000007
#define inf 0x3f3f3f3f

///////////////////////////////////////////////////
#define mem(a, t) memset(a, t, sizeof(a))
#define endl '\n'
template <typename T>
void print(T &&t)
{
    cout << t << '\n';
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
    cout << t << ' ';
    print(forward<Args>(args)...);
}

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

void pre()
{
    return;
}

int cnt = 1;

void solve()
{
    ll r, c;
    cin >> r >> c;
    vector<vector<ll>> vect(2 * r, vector<ll>(2 * c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char d;
            cin >> d;
            if (d == '#')
            {
                vect[2 * i][2 * j] = 1;
                vect[2 * i + 1][2 * j] = 1;
                vect[2 * i][2 * j + 1] = 1;
                vect[2 * i + 1][2 * j + 1] = 1;
            }
        }
    }

    string answer = "S";
    r *= 2;
    c *= 2;
    ll cr = 1, cc = 0;
    vect[0][0] = 0;
    vect[1][0] = 1;
    vector<ll> rv = {0, 1, 0, -1};
    vector<ll> rc = {-1, 0, +1, 0};
    while (cr != 0 || cc != 0)
    {
        // cout<<ceramic<<" "<<clan_caste<<endl;
        if (cr + rv[0] < r && cr + rv[0] >= 0 && cc + rc[0] < c && cc + rc[0] >= 0 && vect[cr + rv[0]][cc + rc[0]] != 1)
        {
            answer += 'W';

            vect[cr + rv[0]][cc + rc[0]] = 1;
            cr += rv[0];
            cc += rc[0];
        }
        else if (cr + rv[1] < r && cr + rv[1] >= 0 && cc + rc[1] < c && cc + rc[1] >= 0 && vect[cr + rv[1]][cc + rc[1]] != 1)
        {
            answer += 'S';

            vect[cr + rv[1]][cc + rc[1]] = 1;
            cr += rv[1];
            cc += rc[1];
        }
        else if (cr + rv[2] < r && cr + rv[2] >= 0 && cc + rc[2] < c && cc + rc[2] >= 0 && vect[cr + rv[2]][cc + rc[2]] != 1)
        {
            answer += 'E';

            vect[cr + rv[2]][cc + rc[2]] = 1;
            cr += rv[2];
            cc += rc[2];
        }
        else if (cr + rv[3] < r && cr + rv[3] >= 0 && cc + rc[3] < c && cc + rc[3] >= 0 && vect[cr + rv[3]][cc + rc[3]] != 1)
        {
            answer += 'N';

            vect[cr + rv[3]][cc + rc[3]] = 1;
            cr += rv[3];
            cc += rc[3];
        }
        else
            break;
    }
    cout << "Case #" << cnt << ":"
         << " " << answer << endl;
    cnt++;
}

signed main()
{
    fast_io;
    pre();
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}