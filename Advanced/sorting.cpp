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
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Bubble Sort
// TC = O(n^2) in worst case, and O(n) in best case
// SC = O(1)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (didSwap == false)
            break;
    }
}

// Insertion Sort
// TC = O(n^2) in worst and average case and O(n) in best case
// SC = O(1)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

// Merge Sort
void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (vec[left] < vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }

        while (left <= mid)
        {
            temp.push_back(vec[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(vec[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            vec[i] = temp[i - low];
        }
    }
}

void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    bubbleSort(arr, n);
    insertionSort(arr, n);
    return 0;
}