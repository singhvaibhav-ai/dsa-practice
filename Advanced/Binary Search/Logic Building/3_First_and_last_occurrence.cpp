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