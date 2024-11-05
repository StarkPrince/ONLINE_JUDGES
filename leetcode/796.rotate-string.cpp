#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};
// @lc code=end
