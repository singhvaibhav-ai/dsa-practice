#include <bits/stdc++.h>
using namespace std;

// Selection Sort
// TC = O(n^2)
// SC = O(1)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Bubble Sort
int main()
{
    return 0;
}