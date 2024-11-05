#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int length = 1;

                while (numSet.find(num + length) != numSet.end())
                {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
// @lc code=end
