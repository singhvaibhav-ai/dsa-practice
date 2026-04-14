#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using Linear Search
// TC = O(n)
// SC = O(1)
int findMinBrute(vector<int> &nums)
{
    int n = nums.size();
    int ans = nums[0];
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, nums[i]);
    }
    return ans;
}

// Optimal Approach using Binary Search
// TC = O(log2 n)
// SC = O(1)
int findMinOptimal(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }
        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int findMinOptimalGemini(const vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
        {
            // Minimum is in the right unsorted part
            low = mid + 1;
        }
        else
        {
            // Minimum is in the left part (including mid)
            high = mid;
        }
    }
    // At the end, low == high, pointing to the minimum element
    return nums[low];
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element in the rotated sorted array is: " << findMinOptimal(nums) << endl;
    cout << "Minimum element using Gemini approach is: " << findMinOptimalGemini(nums) << endl;
    return 0;
}