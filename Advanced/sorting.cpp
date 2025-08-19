#include <bits/stdc++.h>
using namespace std;

// Selection Sort (Selects minimum and swaps)
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

// Bubble Sort (Pushes the max to last by adjacent swaps)
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

// Insertion Sort (takes an element and place it in correct order)
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

// Merge Sort (Divide and Merge)
// TC = O(n*log2(n))
// SC = O(n)
void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }
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

void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

// Quick Sort (Divide and Conquer (partition-based))
// TC = O(n^2) in worst case O(nlogn) in best and average case
// SC = O(logn) in best and average case and O(n) in worst case
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSortHelper(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSortHelper(arr, low, pIndex - 1);
        quickSortHelper(arr, pIndex + 1, high);
    }
}
vector<int> quickSort(vector<int> &nums)
{
    int n = nums.size();
    quickSortHelper(nums, 0, n - 1);
    return nums;
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