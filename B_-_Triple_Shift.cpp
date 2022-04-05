// https://atcoder.jp/contests/arc136/tasks/arc136_b
// Nice question : give it a try

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

struct Node
{
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
};

// construct a linked list class
class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList() : head(NULL), tail(NULL) {}
    void add(int v)
    {
        Node *temp = new Node(v);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void print_ll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void solve()
{
    int n, temp;
    bool bl = true;

    cin >> n;
    vector<int> A(n), B(n);
    cinv(A, n);
    cinv(B, n);

    for (int i = 0; i < n - 2 && bl; i++)
    {
        if (A[i] != B[i])
        {
            if (A[i] == B[i + 2])
            {
                temp = A[i + 2];
                A[i + 2] = A[i + 1];
                A[i + 1] = A[i];
                A[i] = temp;
            }
            else if (A[i] == B[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = A[i + 2];
                A[i + 2] = temp;
            }
            else
            {
                bl = false;
            }
        }
        pv(A);
    }
    if (bl)
        print("Yes");
    else
        print("No");
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