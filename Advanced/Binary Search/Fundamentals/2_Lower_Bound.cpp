#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// TC = O(n)
// SC = O(1)
int lower_bound_brute(vector<int> &nums, int x)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= x)
        {
            return i;
        }
    }
    return n;
}

// Optimal approach
// TC = O(log2 n)
// SC = O(1)
int lower_bound_optimal(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int lower_bound_builtin(vector<int> &nums, int x)
{
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 5;
    int result = lower_bound_optimal(nums, x);
    if (result != nums.size())
    {
        cout << "Lower bound of " << x << " is at index: " << result << endl;
    }
    else
    {
        cout << "Lower bound of " << x << " does not exist in the array." << endl;
    }
}