#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &nums, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= x)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int findCeil(vector<int> &nums, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    int n = nums.size();
    int floor = findFloor(nums, n, x);
    int ceil = findCeil(nums, n, x);
    return {floor, ceil};
}

int main()
{
    vector<int> nums = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    vector<int> result = getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;
    return 0;
}