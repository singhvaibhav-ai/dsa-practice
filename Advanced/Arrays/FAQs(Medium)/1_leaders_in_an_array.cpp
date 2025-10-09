#include <bits/stdc++.h>
using namespace std;

// Leaders in an Array
// Brute Force Approach
// TC = O(n^2)
// SC = O(1)
vector<int> findLeadersBrute(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> leaders;
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader && (leaders.empty() || leaders.back() != nums[i]))
            leaders.push_back(nums[i]);
    }
    return leaders;
}

// Optimal Approach
// TC = O(n)
// SC = O(1)
vector<int> findLeadersOptimal(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> leaders;
    int maxFromRight = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > maxFromRight)
        {
            leaders.push_back(nums[i]);
            maxFromRight = nums[i];
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}