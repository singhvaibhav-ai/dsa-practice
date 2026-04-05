#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// TC = O(n)
// SC = O(1)
vector<int> searchRangeBrute(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    return {first, last};
}

// Optimal approach using bounds
// TC = O(log2 n)
// SC = O(1)
vector<int> searchRangeOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (first == n || nums[first] != target)
    {
        return {-1, -1};
    }
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {first, last};
}

// Optimal approach using binary search
// TC = O(log2 n)
// SC = O(1)
int firstOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurrence(nums, target);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(nums, target);
    return {first, last};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "First and Last Occurrence of " << target << " is at indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}