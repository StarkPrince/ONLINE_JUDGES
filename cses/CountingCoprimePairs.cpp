#include <iostream>
using namespace std;

typedef long long ll;

ll cnt[1000010];
ll cnt2[1000010];

int main()
{

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
            cnt2[i] += cnt[j];
        cnt2[i] = (cnt2[i] * (cnt2[i] - 1)) / 2;
    }
    for (int i = 1000000; i > 0; i--)
    {
        for (int j = 2 * i; j < 1000000; j += i)
            cnt2[i] -= cnt2[j];
    }

    cout << cnt2[1] << endl;
}