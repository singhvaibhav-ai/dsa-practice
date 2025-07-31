#include <bits/stdc++.h>
using namespace std;

// Count all Digits of a Number

// bruteforce approach
// TC= O(log n)
// SC= O(1)
int countDigits(int n)
{
    if (n == 0)
        return 1;
    int count = 0, num = abs(n);
    while (num != 0)
    {
        num = num / 10;
        count++;
    }
    return count;
}

// optimal approach
// TC= O(1)
// SC= O(1)
int countDigitsOptimal(int n)
{
    if (n == 0)
        return 1;
    return log10(abs(n)) + 1;
}

// Count number of odd digits in a number
// TC= O(log n)
// SC= O(1)
int countOddDigits(int n)
{
    int countOdd = 0, num = abs(n);
    if (num == 0)
        return 0;
    while (num != 0)
    {
        int digit = num % 10;
        if (digit % 2 != 0)
            countOdd++;
        num = num / 10;
    }
    return countOdd;
}

// Reverse a number
// TC = O(log n)
// SC = O(1)
int reverseNumber(int n)
{
    int revNum = 0, num = abs(n);
    while (num != 0)
    {
        int digit = num % 10;
        revNum = revNum * 10 + digit;
        num = num / 10;
    }
    return revNum;
}

// Palindrome number
// TC = O(log n)
// SC = O(1)
bool isPalindrome(int n)
{
    int revNum = 0, num = abs(n);
    while (num != 0)
    {
        int digit = num % 10;
        revNum = revNum * 10 + digit;
        num = num / 10;
    }
    return revNum == abs(n);
    // or
    return n == reverseNumber(n);
}

// Return the Largest Digit in a Number
// TC = O(log n)
// SC = O(1)
int largestDigit(int n)
{
    int largest = 0, num = abs(n);
    while (num != 0)
    {
        int digit = num % 10;
        if (digit > largest)
            largest = digit;
        num = num / 10;
    }
    return largest;
}

// Factorial of a given number
// basic loop approach
// TC = O(n)
// SC = O(1)
long long factorial1(int n)
{
    long long fact = 1;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
        return fact;
    }
    return fact;
}

// Recursive approach
// TC = O(n)
// SC = O(n)
long long factorial(int n)
{
    if (n == 0)
        return 1;
    if (n > 0)
        return n * factorial(n - 1);
}

int main()
{
    cout << reverseNumber(-12345);
    return 0;
}