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
int second_highest_occurrence(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = max(maxNum, arr[i]);
    }

    int freq[maxNum + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int firstMax = 0, secondMax = 0;
    for (int i = 0; i <= maxNum; i++)
    {
        if (freq[i] > firstMax)
        {
            secondMax = firstMax;
            firstMax = freq[i];
        }
        else if (freq[i] > secondMax && freq[i] < firstMax)
        {
            secondMax = freq[i];
        }
    }

    if (secondMax == 0)
        return -1; // important edge case fix

    int ans = -1;
    for (int i = 0; i <= maxNum; i++)
    {
        if (freq[i] == secondMax)
        {
            if (ans == -1 || i < ans)
                ans = i;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 1, 4, 7, 9};
    int n = 9;

    return 0;
}