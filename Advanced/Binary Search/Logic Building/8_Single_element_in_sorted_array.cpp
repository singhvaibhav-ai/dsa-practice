#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using XOR
// TC = O(n)
// SC = O(1)
int singleNonDuplicateXOR(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

// Brute Force Approach using Linear Search
// TC = O(n)
// SC = O(1)
int singleNonDuplicateLS(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
        else if (i == n - 1)
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i];
            }
        }
        else
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
    }
    return -1;
}