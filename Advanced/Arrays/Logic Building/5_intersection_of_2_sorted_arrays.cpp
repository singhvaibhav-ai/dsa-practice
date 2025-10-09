#include <bits/stdc++.h>
using namespace std;

// Intersection of two sorted arrays
// Brute Force Approach
// TC = O(n*m)
// SC = O(m)
vector<int> intersectionArrayBrute(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    vector<int> visited(nums2.size(), 0);
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j] && visited[j] == 0)
            {
                ans.push_back(nums2[j]);
                visited[j] = 1;
                break;
            }
            else if (nums2[j] > nums1[i])
                break;
        }
    }
    return ans;
}

// Optimal Approach
// TC = O(n + m)
// SC = O(1)
vector<int> intersectionArrayOptimal(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> intersection;

    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums2[j] < nums1[i])
        {
            j++;
        }
        else
        {
            intersection.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return intersection;
}