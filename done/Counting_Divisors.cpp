#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;

int N, a, cnt, d[maxX + 1];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a;
        d[a]++;
    }
    for (int i = maxX; i >= 1; i--)
    {
        cnt = 0;
        for (int j = i; j <= maxX; j += i)
            cnt += d[j];
        if (cnt >= 2)
        {
            cout << i << endl;
            return 0;
        }
    }
}