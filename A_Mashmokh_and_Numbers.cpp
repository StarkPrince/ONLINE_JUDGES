#include "bits/stdc++.h"
#define p(a) std::cout << a << " "
int main()
{
    int n, k, a;
    std::cin >> n >> k;
    if (k < n / 2 || k && n == 1)
        p(-1);
    else
    {
        p((a = k - n / 2 + 1)), a *= 2, n--;
        while (n--)
            p(a++);
    }
}