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

ll binpow(ll a, ll b)
{
    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// class Bitset:
//     def __init__(self, size: int):
//         self.num = [0]*size

//     def fix(self, idx: int) -> None:
//         self.num[idx] = 1

//     def unfix(self, idx: int) -> None:
//         self.num[idx] = 0

//     def flip(self) -> None:
//         self.num = [1-i for i in self.num]

//     def all(self) -> bool:
//         return all(i == 1 for i in self.num)

//     def one(self) -> bool:
//         return any(i == 1 for i in self.num)

//     def count(self) -> int:
//         return sum(self.num)

//     def toString(self) -> str:
//         return "".join(str(i) for i in self.num)

class Bitset
{
public:
    vector<int> num;
    int cnt, cntflip = 0vector < int > arr;
    int cnt, cntflip;
    Bitset(int size)
    {
        arr.resize(size, 0);
        cnt = 0, cntflip = 0;
    }
    void fix(int idx)
    {
        // means current bit is 0 ,so set it to 1
        if ((arr[idx] + cntflip) % 2 == 0)
        {
            arr[idx]++;
            cnt++;
        }
    }
    void unfix(int idx)
    {
        // means current bit is 1,so set it to 0
        if ((arr[idx] + cntflip) % 2 != 0)
        {
            arr[idx]--;
            cnt--;
        }
    }
    void flip()
    {
        // cnt will flip ,if we flip all the bits
        cnt = arr.size() - cnt;
        cntflip++;
    }
    bool all()
    {
        if (cnt == arr.size())
            return true;
        return false;
    }
    bool one()
    {
        if (cnt >= 1)
            return true;
        return false;
    }
    int count()
    {
        return cnt;
    }
    string toString()
    {
        string ans;
        for (auto &ele : arr)
        {
            if ((cntflip + ele) % 2 == 0)
                ans.push_back('0');
            else
                ans.push_back('1');
        }
        return ans;
    }
    // expected time complexity: O(1)
    Bitset(int size)
    {
        num = vector<int>(size, 0);
    }
    // expected time complexity: O(1)
    void fix(int idx)
    {
        num[idx] = 1;
    }
    // expected time complexity: O(1)
    void unfix(int idx)
    {
        num[idx] = 0;
    }
    // expected time complexity: O(n)
    void flip()
    {
        for (int i = 0; i < num.size(); i++)
            num[i] = 1 - num[i];
    }
    // expected time complexity: O(n)
    bool all()
    {
        for (int i : num)
            if (i != 1)
                return false;
        return true;
    }
    // expected time complexity: O(n)
    bool one()
    {
        for (int i : num)
            if (i == 1)
                return true;
        return false;
    }
    // expected time complexity: O(n)
    int count()
    {
        int res = 0;
        for (int i : num)
            res += i;
        return res;
    }
    // expected time complexity: O(n)
    string toString()
    {
        string res = "";
        for (int i : num)
            res += to_string(i);
        return res;
    }
};

// obj = Bitset(arg[0][0])

// for i, j in zip(query[1:], arg[1:]):
//     if j:
//         print(obj.__getattribute__(i)(*j))
//     else:
//         print(obj.__getattribute__(i)())

void solve()
{
}

int32_t main()
{

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}