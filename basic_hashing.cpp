#include <bits/stdc++.h>
using namespace std;

// Highest occurring element in an array
// Brute force approach
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

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 1, 4, 7, 9};
    int n = 9;

    return 0;
}