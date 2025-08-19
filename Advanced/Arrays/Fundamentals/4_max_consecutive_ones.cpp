#include <bits/stdc++.h>
using namespace std;

// Maximum Consecutive Ones
// TC = O(n)
// SC = O(1)
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            if (count > maxCount)
                maxCount = count;
        }
        else
        {
            count = 0;
        }
    }
    return maxCount;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}