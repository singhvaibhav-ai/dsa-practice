#include <bits/stdc++.h>
using namespace std;

// Second Largest Element
// Brute Force Solution
// TC = O(nlogn + n)
// SC = O(1)
int second_largest_brute(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return -1;
    sort(nums.begin(), nums.end());
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] != nums[n - 1])
            return nums[i];
    }
    return -1;
}

// Better Solution
// TC = O(2n)
// SC = O(1)
int second_largest_better(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return -1;
    int largest = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    int sec_largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > sec_largest && nums[i] < largest)
        {
            sec_largest = nums[i];
        }
    }
    if (sec_largest == INT_MIN)
        return -1;
    return sec_largest;
}

// Optimal Solution
// TC = O(n)
// SC = O(1)
int second_largest_optimal(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return -1;
    int largest = INT_MIN;
    int secLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            secLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secLargest && nums[i] < largest)
        {
            secLargest = nums[i];
        }
    }
    if (secLargest == INT_MIN)
        return -1;
    return secLargest;
}

int main()
{
    return 0;
}