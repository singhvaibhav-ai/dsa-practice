#include <bits/stdc++.h>
using namespace std;
// TC = O(log2 n)
// SC = O(1) for iterative, O(log n) for recursive due to call
// Iterative approach
int binary_search_iterative(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive approach
int binary_search_recursive(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] > target)
    {
        return binary_search_recursive(nums, target, low, mid - 1);
    }
    else
    {
        return binary_search_recursive(nums, target, mid + 1, high);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = binary_search_recursive(nums, target, 0, nums.size() - 1);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}