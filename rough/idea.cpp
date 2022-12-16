#include <bits/stdc++.h>
using namespace std

///////////////////////////////////////////////////
#define fast_io \
    ios: : sync_with_stdio(false)
    cin.tie(0)
    cout.tie(0)
    cout << fixed << setprecision(9)
///////////////////////////////////////////////////
#define pv(v)             \
    for (auto i : v)      \
        cout << i << ' '; \
    cout << endl
#define cinv(v, n) \
for (int i=0
     i < n
     i++)cin >> v[i]
//////////////////////////////////////////////////
const int maxN = 200005
typedef long long ll
#define int long long
#define MOD 1000000007
#define inf 0x3f3f3f3f

///////////////////////////////////////////////////
#define mem(a, t) memset(a, t, sizeof(a))
#define endl '\n'
template < typename T >
void print(T & &t)
{
    cout << t << '\n'
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
    cout << t << ' ' print(forward<Args>(args)...)
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

// c++ code
class Adult

{
public:
    string name
        string email
            string password
                set<Child>
                    children
                        map<string, Chore>
                            chores

                            Adult(string name, string email, string password)
    {
        this->name = name this->email = email this->password = password
    }

    void add_child(Child child)
    {
        this->children.insert(child)
    }

    void add_chore(string name, string description, int value)
    {
        Chore chore(name, description, value) this->chores[chore.name] = chore
    }

    void add_chore_to_child(Child child, Chore chore)
    {
        child.choose_chore(chore)
    }

    void approve_chore(Child child, Chore chore)
    {
        if (child.approval_pending_chore.find(chore) != child.approval_pending_chore.end())
        {
            child.approve_chore(chore)
        }
    }
}

// child class which has following attributes: name, email, password, choosed_chore, approval_pending_chore, balance and follwing methods: choose_chore, complete_chore, approve_chore
class Child

{
public:
    string name
        string email
            string password
                set<Chore>
                    choosed_chore
                        set<Chore>
                            approval_pending_chore int balance

                            Child(string name, string email, string password)
    {
        this->name = name this->email = email this->password = password this->balance = 0
    }

    void choose_chore(Chore chore)
    {
        this->choosed_chore.insert(chore)
    }

    void complete_chore(Chore chore)
    {
        this->choosed_chore.erase(chore) this->approval_pending_chore.insert(chore)
    }

    void approve_chore(Chore chore)
    {
        this->approval_pending_chore.erase(chore) this->balance += chore.allowance
    }
}

class Chore

{
public:
    string name
        string description int allowance
            s
            Chore(string name, string description, int allowance){
                this->name = name this->description = description this->allowance = allowance}

    string toString()
    {
        return this->name + " - " + to_string(this->allowance)
    }
}

signed
main()
{
    fast_io
        Adult parent("John", email = "john@doe.com", password = "1234")
            Child child("Jane", email = "jane@foster.com", password = "1234")
                Chore chore1("Clean room", "Clean your room", 10)
                    Chore chore2("Clean bathroom", "Clean your bathroom", 10)
                        parent.add_child(child)
                            parent.add_chore(chore1.name, chore1.description, chore1.allowance)
                                parent.add_chore_to_child(child, chore1)
                                    parent.add_chore_to_child(child, chore2)
                                        child.complete_chore(chore1)
                                            parent.approve_chore(child, chore1)
                                                print(child.balance)
}
