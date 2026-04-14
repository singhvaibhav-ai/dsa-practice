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

// Optimal Approach using Binary Search
// TC = O(log2 n)
// SC = O(1)
int findKRotationOptimal(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    cout << "The array is rotated " << findKRotationOptimal(nums) << " times." << endl;
    return 0;
}