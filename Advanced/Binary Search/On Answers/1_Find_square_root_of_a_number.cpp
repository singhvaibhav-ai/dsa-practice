#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using Linear Search
// TC = O(root(n))
// SC = O(1)
int floorSqrtLS(int n)
{
    if (n == 0)
        return 0;
    int ans = 1;
    for (int i = 1; i <= n / i; i++)
    {
        ans = i;
    }
    return ans;
}

// Optimal Approach using Binary Search
// TC = O(log2 n)
// SC = O(1)
int floorSqrtBS(int n)
{
    if (n == 0)
        return 0;
    int low = 1, high = n / 2;
    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid <= n / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 16;
    cout << "Floor of square root of " << n << " is: " << floorSqrtBS(n) << endl;
    return 0;
}