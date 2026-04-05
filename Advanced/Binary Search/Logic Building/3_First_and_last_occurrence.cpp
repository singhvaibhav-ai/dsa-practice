#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// TC = O(n)
// SC = O(1)
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    return {first, last};
}

// Optimal approach using bounds
// TC = O(log2 n)
// SC = O(1)
vector<int> searchRangeOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (first == n || nums[first] != target)
    {
        return {-1, -1};
    }
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {first, last};
}

// Optimal approach using binary search
// TC = O(log2 n)
// SC = O(1)