#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using Linear Search
// TC = O(n)
// SC = O(1)
int linearSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
{
    return (linearSearch(nums, k) != -1);
}

// Optimal Approach using Binary Search