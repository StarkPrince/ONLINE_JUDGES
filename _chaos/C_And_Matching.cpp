#include <bits/stdc++.h>
using namespace std;
int n, t, k, x[1000005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            x[i] = i;
        if (k != n - 1)
            swap(x[k], x[0]);
        else
            swap(x[n - 2], x[0]), swap(x[1], x[n - 4]);
        if (n == 4 && k == 3)
            printf("-1\n");
        else
            for (int a = 0; a < n / 2; a++)
                printf("%d %d\n", x[a], x[n - a - 1]);
    }
}