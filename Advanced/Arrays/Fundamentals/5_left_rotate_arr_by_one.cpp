#include <bits/stdc++.h>
using namespace std;
// Left Rotate an array by one
// TC = O(n)
// SC = O(1)

void leftRotateByOne(vector<int> &nums)
{
    int n = nums.size();
    int first = nums[0];
    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = first;
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 2};
    leftRotateByOne(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}