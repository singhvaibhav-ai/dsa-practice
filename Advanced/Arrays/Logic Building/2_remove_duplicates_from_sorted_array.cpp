#include <bits/stdc++.h>
using namespace std;

// --- Brute Force Approach ---
// TC = O(n log n)
// SC = O(n)
int removeDuplicatesBrute(vector<int> &arr)
{
    int n = arr.size();
    set<int> s;

    // Insert all elements into the set (automatically removes duplicates)
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // Copy unique elements back to the array
    int index = 0;
    for (int val : s)
    {
        arr[index++] = val;
    }

    // Sort to maintain sorted order
    sort(arr.begin(), arr.begin() + index);

    return index; // New length
}

// --- Optimal Approach ---
// TC = O(n)
// SC = O(1)
int removeDuplicatesOptimal(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1; // New length
}

// --- Helper to Print First k Elements ---
void printArray(const vector<int> &arr, int k)
{
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// --- Main Function ---
int main()
{
    vector<int> arr1 = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    vector<int> arr2 = arr1;

    cout << "Original Array: ";
    printArray(arr1, arr1.size());

    int lenBrute = removeDuplicatesBrute(arr1);
    cout << "After Brute Force: ";
    printArray(arr1, lenBrute);
    cout << "New Length: " << lenBrute << endl;

    int lenOptimal = removeDuplicatesOptimal(arr2);
    cout << "After Optimal: ";
    printArray(arr2, lenOptimal);
    cout << "New Length: " << lenOptimal << endl;

    return 0;
}
