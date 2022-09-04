#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, k;
vector<vector<int>> dp(1000, vector<int>(1000, 0));
int solve(int i, int k)
{
    if (i == s.size() && k == 0)
        return dp[i][k] = 1;
    if (i == s.size() || s[i] - '0' % 2 == 0)
        return dp[i][k] = 0;
    if (dp[i][k] != 0)
        return dp[i][k];
    int ans = 0;
    while (i < s.size())
    {
        if ((s[i] - '0') % 2 == 1 && solve(i + 1, k - 1) == 1)
            ans += 1;
        i++;
    }
    return dp[i][k] = ans;
}

signed main()
{
    cin >> n >> m >> k;
    cin >> s;
    cout << solve(0, k) << endl;
}