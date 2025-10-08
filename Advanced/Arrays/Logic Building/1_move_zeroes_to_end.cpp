#include <bits/stdc++.h>
using namespace std;

// --- Brute Force Approach ---
// TC = O(n)
// SC = O(n)
void moveZeroesToEndBrute(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    for (int i = 0; i < (int)temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}

// --- Optimal Approach (Version 1) ---
// TC = O(n)
// SC = O(1)
// Simpler, may self-swap
void moveZeroesToEndOptimalV1(vector<int> &arr)
{
    int n = arr.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// --- Optimal Approach (Version 2) ---
// TC = O(n)
// SC = O(1)
// Avoids self-swaps by finding first zero index
void moveZeroesToEndOptimalV2(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;

    // Find index of first zero
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return; // No zeros found

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// --- Helper to Print Array ---
void printArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// --- Main Function ---
int main()
{
    vector<int> arr1 = {0, 1, 0, 3, 12};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    cout << "Original Array: ";
    printArray(arr1);

    moveZeroesToEndBrute(arr1);
    cout << "After Brute Force: ";
    printArray(arr1);

    moveZeroesToEndOptimalV1(arr2);
    cout << "After Optimal V1: ";
    printArray(arr2);

    moveZeroesToEndOptimalV2(arr3);
    cout << "After Optimal V2: ";
    printArray(arr3);

    return 0;
}
