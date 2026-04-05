#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// TC = O(n)
// SC = O(1)
int upper_bound_brute(vector<int> &nums, int x)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > x)
        {
            return i;
        }
    }
    return n;
}
