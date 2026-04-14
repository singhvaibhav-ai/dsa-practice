#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// TC = O(n)
// SC = O(1)
int findKRotationBrute(vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < ans)
        {
            ans = nums[i];
            index = i;
        }
    }
    return index;
}
