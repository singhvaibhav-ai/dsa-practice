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

int main()
{
    int n;
    cin >> n;
    cout << nNumbersSum(n);
    return 0;
}