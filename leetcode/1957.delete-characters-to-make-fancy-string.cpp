#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        ans.push_back(s[0]);
        int n = s.size(), cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ans.back())
            {
                cnt++;
                if (cnt < 3)
                    ans.push_back(s[i]);
            }
            else
            {
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
// @lc code=end
