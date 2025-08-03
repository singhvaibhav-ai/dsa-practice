#include <bits/stdc++.h>
using namespace std;

// Sum of Array Elements
// TC=O(n)
// SC=O(1)
int sumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

// Count of odd numbers in array
// TC = O(n)
// SC = O(1)
int countOdd(int arr[], int n)
{
    int oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            oddCount = oddCount + 1;
        }
    }
    return oddCount;
}

// Check if the Array is Sorted
// TC = O(n)
// SC = O(1)
bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Reverse an Array
// TC = O(n)
// SC = O(n)
void reverseArray(int arr[], int n)
{
    int tempArr[n];
    for (int i = 0; i < n; i++)
    {
        tempArr[i] = arr[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = tempArr[i];
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << countOdd(arr, 5) << endl;
    return 0;
}