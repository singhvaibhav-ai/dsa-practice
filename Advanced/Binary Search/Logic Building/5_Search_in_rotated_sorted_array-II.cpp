#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using Linear Search
// TC = O(n)
// SC = O(1)
int linearSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
{
    return (linearSearch(nums, k) != -1);
}

// Optimal Approach using Binary Search
// TC = O(log2 n) in the best case, O(n) in the worst case due to duplicates
// SC = O(1)
bool searchInARotatedSortedArrayII(const vector<int> &nums, int k)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Base case found
        if (nums[mid] == k)
        {
            return true;
        }

        // Edge case: Duplicates make it impossible to identify the sorted half
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue; // Skip the rest and recalculate mid
        }

        // Left half is sorted
        if (nums[low] <= nums[mid])
        {
            // Is the target within the strictly sorted left half?
            if (nums[low] <= k && k < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else
        {
            // Is the target within the strictly sorted right half?
            if (nums[mid] < k && k <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    cout << "Using Linear Search: " << (searchInARotatedSortedArrayII(nums, target) ? "Found" : "Not Found") << endl;
    cout << "Using Binary Search: " << (searchInARotatedSortedArrayII(nums, target) ? "Found" : "Not Found") << endl;

    return 0;
}