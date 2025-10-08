#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

// --- Brute Force Approach 1 ---
// TC = O(nlogn) + O(mlogm) + O((n+m) log(n+m))
// SC = O(n+m)
vector<int> unionArrayBrute1(const vector<int> &nums1, const vector<int> &nums2)
{
    set<int> s;
    for (int num : nums1)
        s.insert(num);
    for (int num : nums2)
        s.insert(num);

    vector<int> unionArr(s.begin(), s.end());
    return unionArr;
}

// --- Optimal Approach 1 (Two Pointer Technique) ---
// TC = O(n + m)
// SC = O(n + m)
vector<int> unionArrayOptimal1(const vector<int> &nums1, const vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> uni;

    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (uni.empty() || uni.back() != nums1[i])
                uni.push_back(nums1[i]);

            if (nums1[i] == nums2[j])
                j++;
            i++;
        }
        else
        {
            if (uni.empty() || uni.back() != nums2[j])
                uni.push_back(nums2[j]);
            j++;
        }
    }

    while (i < n)
    {
        if (uni.empty() || uni.back() != nums1[i])
            uni.push_back(nums1[i]);
        i++;
    }

    while (j < m)
    {
        if (uni.empty() || uni.back() != nums2[j])
            uni.push_back(nums2[j]);
        j++;
    }

    return uni;
}

// --- Optimal Approach 2 (Single Loop with Sentinels) ---
// TC = O(n + m)
// SC = O(n + m)
vector<int> unionArrayOptimal2(const vector<int> &nums1, const vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> uni;

    while (i < n || j < m)
    {
        int val1 = (i < n) ? nums1[i] : INT_MAX;
        int val2 = (j < m) ? nums2[j] : INT_MAX;
        int candidate;

        if (val1 < val2)
        {
            candidate = val1;
            i++;
        }
        else if (val2 < val1)
        {
            candidate = val2;
            j++;
        }
        else
        {
            candidate = val1;
            i++;
            j++;
        }

        if (candidate != INT_MAX)
        {
            if (uni.empty() || uni.back() != candidate)
                uni.push_back(candidate);
        }
    }

    return uni;
}

// --- Helper to Print Vector ---
void printVector(const vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

// --- Main Function ---
int main()
{
    vector<int> nums1 = {1, 2, 4, 5, 6};
    vector<int> nums2 = {2, 3, 5, 7};

    cout << "Array 1: ";
    printVector(nums1);
    cout << "Array 2: ";
    printVector(nums2);
    cout << endl;

    cout << "Brute Force 1: ";
    printVector(unionArrayBrute1(nums1, nums2));

    cout << "Optimal 1 (Two Pointer): ";
    printVector(unionArrayOptimal1(nums1, nums2));

    cout << "Optimal 2 (Single Loop + Sentinels): ";
    printVector(unionArrayOptimal2(nums1, nums2));

    return 0;
}
