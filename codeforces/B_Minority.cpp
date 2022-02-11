// https://codeforces.com/contest/1633/problem/B
#include <stdio.h>
#include <string.h>

#define N 200000

int main()
{
    int t;

    scanf("%d", &t);
    while (t--)
    {
        static char cc[N + 1];
        int n, i, k0, k1;

        scanf("%s", cc), n = strlen(cc);
        k0 = k1 = 0;
        for (i = 0; i < n; i++)
            if (cc[i] == '0')
                k0++;
            else
                k1++;
        printf("%d\n", k0 == k1 ? k0 - 1 : (k0 < k1 ? k0 : k1));
    }
    return 0;
}
