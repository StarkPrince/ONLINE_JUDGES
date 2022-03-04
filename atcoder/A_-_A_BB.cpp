// https://atcoder.jp/contests/arc136/tasks/arc136_a
// Nice regular problem, the problem is to find the minimum lexicographic string posssible
// so we will replace BA by AB and BB with A
// since the second replace causes a size change, we can't just use arrays
// so will have to use LinkedList or some other data structure
// i used LinkedList connected all the nodes together and then iterate if the next node is BB then we can replace it with A and dont iterate the ptr
// while iterating the ptr, if the next node is AB then we can replace it with BA and  iterate the ptr

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
    char val;
    Node *next;
    Node(char v) : val(v), next(NULL) {}
};

// construct a linked list class
class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList() : head(NULL), tail(NULL) {}
    void add(char v)
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
            cout << temp->val << "";
            temp = temp->next;
        }
        cout << endl;
    }
};

void solve()
{
    int n, i = 0;
    char s;
    cin >> n;
    LinkedList l;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        l.add(s);
    }
    // traverse through the linked list
    Node *temp = l.head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->val == 'B' && temp->next->val == 'B')
        {
            temp->val = 'A';
            temp->next = temp->next->next;
            continue;
        }
        else if (temp->val == 'B' && temp->next->val == 'A')
        {
            temp->val = 'A';
            temp->next->val = 'B';
        }
        temp = temp->next;
    }
    l.print_ll();
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