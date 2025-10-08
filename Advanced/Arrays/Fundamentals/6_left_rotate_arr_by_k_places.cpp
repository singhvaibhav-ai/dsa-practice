#include <bits/stdc++.h>
using namespace std;

// --- Brute Force Approach ---
// TC: O(n + k)
// SC: O(k)
void leftRotateBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    int a = k % n;

    vector<int> temp;
    for (int i = 0; i < a; i++)
        temp.push_back(nums[i]);

    for (int i = a; i < n; i++)
        nums[i - a] = nums[i];

    for (int i = 0; i < a; i++)
        nums[n - a + i] = temp[i];
}

// --- Helper Function for Optimal Approach ---
void reverseVec(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// --- Optimal Approach ---
// TC: O(n), SC: O(1)
void leftRotateOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    int a = k % n;

    reverseVec(nums, 0, a - 1);
    reverseVec(nums, a, n - 1);
    reverseVec(nums, 0, n - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    // leftRotateBrute(nums, k);
    leftRotateOptimal(nums, k);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
