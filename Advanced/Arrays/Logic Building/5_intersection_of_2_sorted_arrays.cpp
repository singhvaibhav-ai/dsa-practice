#include <bits/stdc++.h>
using namespace std;

// intersection of 2 sorted arrays
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> inter;

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
            if (inter.empty() || inter.back() != nums1[i])
                inter.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return inter;
}