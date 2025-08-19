#include <bits/stdc++.h>
using namespace std;
// Largest Element
// TC = O(n)
// SC = O(1)
int largestElement(vector<int> &nums)
{
    int n = nums.size();
    int max = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }
    return max;
}
int main()
{
    vector<int> nums = {3, 2, 1, 5, 2};
    cout << largestElement(nums) << endl;
    return 0;
}