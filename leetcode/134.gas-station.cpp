#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start

// [1,2,3,4,5],
// [3,4,5,1,2]
// [-2, -4, -6, -3, 0]

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> diff;
        int n = gas.size();
        for (int i = 0; i < gas.size(); i++)
        {
            diff.push_back(gas[i] - cost[i]);
            cout << diff[i] << endl;
        }
        int mn = diff[0];
        for (int i = 1; i < gas.size(); i++)
        {
            diff[i] = diff[i] + diff[i - 1];
            mn = min(mn, diff[i]);
        }
        if (diff[n - 1] < 0)
        {
            return -1;
        }

        for (int i = 0; i < gas.size(); i++)
        {
            if (diff[i] == mn)
            {
                return (i + 1) % n;
            }
        }
        return -1;
    }
};
// @lc code=end
