#include <bits/stdc++.h>
using namespace std;

// Linear Search Approach
// TC = O(n)
// SC = O(1)
int searchLinear(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}
