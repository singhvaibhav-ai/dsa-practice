#include <bits/stdc++.h>
using namespace std;

// Sum of First n Numbers
//  TC = O(n)
//  SC = O(n) due to recursion stack
int nNumbersSum(int n)
{
    if (n == 0)
        return 0;
    return n + nNumbersSum(n - 1);
}

// Factorial of a Given Number
//  TC = O(n)
//  SC = O(n) due to recursion stack
long long int factorial(int i, int n)
{
    if (i > n)
        return 1;
    return i * factorial(i + 1, n);
}

// Sum of Array Elements
// TC = O(n)
// SC = O(n) due to recursion stack
int sum(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return 0;
    return nums[i] + sum(nums, i + 1);
}
int arraySum(vector<int> &nums)
{
    return sum(nums, 0);
}

// Reverse a string
// TC = O(n/2)
// SC = O(n/2)
void reverse(vector<char> &s, int left, int right)
{
    if (left >= right)
        return;
    swap(s[left], s[right]);
    reverse(s, left + 1, right - 1);
}
vector<char> reverseString(vector<char> &s)
{
    int left = 0;
    int right = s.size() - 1;
    reverse(s, left, right);
    return s;
}

// Check if String is Palindrome or Not
// TC = O(n)
// SC = O(n)
bool isPalindrome(string &s, int left, int right)
{
    if (left >= right)
        return true;
    if (s[left] != s[right])
        return false;
    return isPalindrome(s, left + 1, right - 1);
}
bool palindromeCheck(string &s)
{
    int left = 0;
    int right = s.size() - 1;
    return isPalindrome(s, left, right);
}

// Check if a Number is Prime or Not
// TC = O(sqrt(n))
// SC = O(sqrt(n))
bool checkPrimeHelper(int num, int n)
{
    if (n * n > num)
        return true;
    if (num % n == 0)
        return false;
    return checkPrimeHelper(num, n + 1);
}

bool checkPrime(int num)
{
    if (num <= 1)
        return false;
    return checkPrimeHelper(num, 2);
}

// Reverse an Array
// TC = O(n/2)
// SC = O(n/2) due to recursion stack
void reverse(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    swap(nums[left], nums[right]);
    reverse(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int> &nums)
{
    reverse(nums, 0, nums.size() - 1);
    return nums;
}

// Check if the Array is Sorted
// TC = O(n)
// SC = O(n) due to recursion stack
bool isSortedHelper(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return true;
    if (nums[i] < nums[i - 1])
        return false;
    return isSortedHelper(nums, i + 1);
}

bool isSorted(vector<int> &nums)
{
    return isSortedHelper(nums, 1);
}

int main()
{
    int n;
    cin >> n;
    cout << nNumbersSum(n);
    return 0;
}