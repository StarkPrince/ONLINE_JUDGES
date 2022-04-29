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
    ll ceramic = 1, clan_caste = 0;
    vect[0][0] = 0;
    vect[1][0] = 1;
    vector<ll> ravi = {0, 1, 0, -1};
    vector<ll> royal_champ = {-1, 0, +1, 0};
    while (ceramic != 0 || clan_caste != 0)
    {
        // cout<<ceramic<<" "<<clan_caste<<endl;
        if (ceramic + ravi[0] < r && ceramic + ravi[0] >= 0 && clan_caste + royal_champ[0] < c && clan_caste + royal_champ[0] >= 0 && vect[ceramic + ravi[0]][clan_caste + royal_champ[0]] != 1)
        {
            answer += 'W';

            vect[ceramic + ravi[0]][clan_caste + royal_champ[0]] = 1;
            ceramic += ravi[0];
            clan_caste += royal_champ[0];
        }
        else if (ceramic + ravi[1] < r && ceramic + ravi[1] >= 0 && clan_caste + royal_champ[1] < c && clan_caste + royal_champ[1] >= 0 && vect[ceramic + ravi[1]][clan_caste + royal_champ[1]] != 1)
        {
            answer += 'S';

            vect[ceramic + ravi[1]][clan_caste + royal_champ[1]] = 1;
            ceramic += ravi[1];
            clan_caste += royal_champ[1];
        }
        else if (ceramic + ravi[2] < r && ceramic + ravi[2] >= 0 && clan_caste + royal_champ[2] < c && clan_caste + royal_champ[2] >= 0 && vect[ceramic + ravi[2]][clan_caste + royal_champ[2]] != 1)
        {
            answer += 'E';

            vect[ceramic + ravi[2]][clan_caste + royal_champ[2]] = 1;
            ceramic += ravi[2];
            clan_caste += royal_champ[2];
        }
        else if (ceramic + ravi[3] < r && ceramic + ravi[3] >= 0 && clan_caste + royal_champ[3] < c && clan_caste + royal_champ[3] >= 0 && vect[ceramic + ravi[3]][clan_caste + royal_champ[3]] != 1)
        {
            answer += 'N';

            vect[ceramic + ravi[3]][clan_caste + royal_champ[3]] = 1;
            ceramic += ravi[3];
            clan_caste += royal_champ[3];
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