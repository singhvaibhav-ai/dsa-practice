#include <bits/stdc++.h>
using namespace std;

// Reverse a String
// brute force approach
// TC = O(n)
// SC = O(n)
void reverseString(string &str)
{
    int n = str.length();
    string dupStr = str;
    for (int i = 0; i < n; i++)
    {
        str[i] = dupStr[n - i - 1];
    }
}

// Optimal approach
void reverseStringOptimal(string &str)
{
    int n = str.length();
    int left = 0, right = n - 1;
    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main()
{
    return 0;
}