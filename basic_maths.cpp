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

int main()
{
    cout << countDigits(-12345);
    return 0;
}