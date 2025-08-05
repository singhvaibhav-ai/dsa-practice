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
// TC = O(n)
// SC = O(1)
void reverseStringOptimal(string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// Palindrome Check
// TC = O(n)
// SC = O(1)
bool isPalindrome(string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Largest odd number in a string
// TC = O(n)
// SC = O(1)
string largestOddNumber(string &s)
{
    int j = -1, n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return "";
    int i = 0;
    while (i <= j)
    {
        if (s[i] != '0')
            break;
        i++;
    }
    return s.substr(i, j - i + 1);
}

int main()
{
    return 0;
}