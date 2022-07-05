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

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i % 3, column = j - j % 3;
    for (int x = 0; x < 9; x++)
        if (board[x][j] == val)
            return false;
    for (int y = 0; y < 9; y++)
        if (board[i][y] == val)
            return false;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (board[row + x][column + y] == val)
                return false;
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if (i == 9)
        return true;
    if (j == 9)
        return solveSudoku(board, i + 1, 0);
    if (board[i][j] != '.')
        return solveSudoku(board, i, j + 1);

    for (char c = '1'; c <= '9'; c++)
    {
        if (check(board, i, j, c))
        {
            board[i][j] = c;
            if (solveSudoku(board, i, j + 1))
                return true;
            board[i][j] = '.';
        }
    }

    return false;
}

void solve()
{
    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    solveSudoku(board, 0, 0);
    for (auto i : board)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }
}

signed main()
{
    fast_io;
    pre();
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
