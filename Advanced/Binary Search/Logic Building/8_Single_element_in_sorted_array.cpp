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

// Optimal Approach using Binary Search
// TC = O(log2 n)
// SC = O(1)
int singleNonDuplicateBS(vector<int> &nums)
{
    int n = nums.size();

    // Edge cases for boundary elements
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    // Search space narrowed strictly between the boundaries
    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If mid is the single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        // Check if we are in the left half (pattern is intact)
        // Even index matches next, OR Odd index matches previous
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
            (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            // The single element must be to our right
            low = mid + 1;
        }
        else
        {
            // The pattern is broken, the single element is to our left
            high = mid - 1;
        }
    }

    return -1;
}

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    // Notice we use < instead of <=.
    // We terminate when low == high, pointing exactly at our target.
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // Force mid to be an even index (the start of a hypothetical pair)
        if (mid % 2 == 1)
        {
            mid--;
        }

        // Because mid is even and low < high, mid + 1 is strictly within bounds.
        // Check if the pair is intact.
        if (nums[mid] == nums[mid + 1])
        {
            // Pattern is intact. The single element is further right.
            // We add 2 because we know mid and mid+1 are not the answer.
            low = mid + 2;
        }
        else
        {
            // Pattern is broken. The single element is either at mid or to the left.
            high = mid;
        }
    }

    // When low == high, we've pinned down the single element.
    return nums[low];
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "The single non-duplicate element is: " << singleNonDuplicateBS(nums) << endl;
    return 0;
}