#include <bits/stdc++.h>
using namespace std;
// Linear Search
// TC = O(n)
// SC = O(1)
int linearSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 4;
    cout << linearSearch(nums, target) << endl;
    return 0;
}