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