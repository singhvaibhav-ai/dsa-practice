#include <bits/stdc++.h>
using namespace std;

// Highest occurring element in an array
// Brute force approach
// TC = O(n^2)
// SC = O(1) → technically O(10^4) but considered constant
int highest_occurrence(int arr[], int n)
{
    int vis[10001] = {0};
    int maxCount = 0, el = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (vis[arr[i]] == 0)
        {
            vis[arr[i]] = 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                el = arr[i];
            }
            else if (count == maxCount && arr[i] < el)
            {
                el = arr[i];
            }
        }
    }
    return el;
}

// Optimal Approach
// TC = O(n)
// SC = O(max(arr)) → better than fixed-size 10^4
int highest_occurrence_optimal(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = max(maxNum, arr[i]);
    }
    int hash[maxNum + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int maxCount = 0, el = -1;
    for (int i = 0; i <= maxNum; i++)
    {
        if (hash[i] > maxCount)
        {
            maxCount = hash[i];
            el = i;
        }
        else if (hash[i] == maxCount && i < el)
        {
            el = i;
        }
    }
    return el;
}

// Second Highest Occurring Element
// Brute force approach
// TC = O(n^2)
// SC = O(max(arr))
int second_highest_occurrence_brute(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = std::max(maxNum, arr[i]);
    }

    int vis[maxNum + 1] = {0};
    int maxFreq = 0, secondMaxFreq = 0;
    int el1 = -1, el2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (vis[arr[i]] == 0)
        {
            vis[arr[i]] = 1;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                    cnt++;
            }

            if (cnt > maxFreq)
            {
                secondMaxFreq = maxFreq;
                el2 = el1;
                maxFreq = cnt;
                el1 = arr[i];
            }
            else if (cnt == maxFreq && arr[i] < el1)
            {
                el1 = arr[i];
            }
            else if (cnt > secondMaxFreq && cnt < maxFreq)
            {
                secondMaxFreq = cnt;
                el2 = arr[i];
            }
            else if (cnt == secondMaxFreq && arr[i] < el2)
            {
                el2 = arr[i];
            }
        }
    }

    return (secondMaxFreq == 0) ? -1 : el2;
}

// Optimal approach
// TC = O(n)
// SC = O(max(arr))
int second_highest_occurrence_optimal(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = std::max(maxNum, arr[i]);
    }
    int freq[maxNum + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int firstMax = 0, secondMax = 0;
    int el1 = -1, el2 = -1;
    for (int i = 0; i <= maxNum; i++)
    {
        int cnt = freq[i];
        if (cnt == 0)
            continue;

        if (cnt > firstMax)
        {
            secondMax = firstMax;
            el2 = el1;
            firstMax = cnt;
            el1 = i;
        }
        else if (cnt == firstMax && i < el1)
        {
            el1 = i;
        }
        else if (cnt > secondMax && cnt < firstMax)
        {
            secondMax = cnt;
            el2 = i;
        }
        else if (cnt == secondMax && i < el2)
        {
            el2 = i;
        }
    }
    return (secondMax == 0) ? -1 : el2;
}

// Sum of Highest and Lowest Frequency
// Brute force approach
// TC = O(n^2)
// SC = O(1)
int sum_highest_lowest_frequency_brute(int arr[], int n)
{
    int maxFreq = 0;
    int minFreq = n + 1;
    int vis[10001] = {0};
    for (int i = 0; i < n; i++)
    {
        if (vis[arr[i]] == 0)
        {
            vis[arr[i]] = 1;
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                    count++;
            }
            if (count > maxFreq)
                maxFreq = count;
            if (count < minFreq)
                minFreq = count;
        }
    }
    return maxFreq + minFreq;
}

// Sum of Highest and Lowest Frequency
// Optimal approach
// TC = O(n)
// SC = O(max(arr))
int sum_highest_lowest_frequency(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
        maxNum = max(maxNum, arr[i]);

    int freq[maxNum + 1] = {0};

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    int highestFreq = 0;
    int lowestFreq = n + 1; // worst case: frequency can't exceed n

    for (int i = 0; i <= maxNum; i++)
    {
        if (freq[i] > 0)
        {
            highestFreq = max(highestFreq, freq[i]);
            lowestFreq = min(lowestFreq, freq[i]);
        }
    }

    return highestFreq + lowestFreq;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 1, 4, 7, 9};
    int n = 9;

    return 0;
}