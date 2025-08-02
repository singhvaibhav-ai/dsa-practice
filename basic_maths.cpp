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

// Check if the Number is Armstrong
// TC = O(log n * log2(log n)) // log n for number of digits, log2(log n) for power calculation
// SC = O(1)
bool isArmstrong(int n)
{
    int originalNum = n, sum = 0, count = log10(abs(n)) + 1;
    while (n != 0)
    {
        int digit = n % 10;
        sum += pow(digit, count);
        n /= 10;
    }
    return sum == originalNum;
}

// Check for perfect number
// A perfect number is a positive integer that is equal to the sum of its proper divisors
// Brute force approach
// TC = O(n)
// SC = O(1)
bool isPerfect(int n)
{
    if (n <= 0)
        return false;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return (sum == n);
}

// Optimized approach
// TC = O(sqrt(n))
// SC = O(1)
bool isPerfectOptimal(int n)
{
    if (n <= 1)
        return false;
    int sum = 1; // 1 is a proper divisor of any positive integer
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i) // Avoid adding the square root twice
                sum += n / i;
        }
    }
    return (sum == n);
}

// Check for Prime Number
// Brute force approach
// TC = O(n)
// SC = O(1)
bool isPrimeBruteForce(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// Optimal approach
// TC = O(sqrt(n))
// SC = O(1)
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Count of prime numbers till N
int countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

// GCD of Two Numbers
// TC = O(min(a, b))
// SC = O(1)
int gcd(int a, int b)
{
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
}

// Optimal approach using Euclidean algorithm
// TC = O(log(min(a, b)))
// SC = O(1)
int gcdEuclidean(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // bachpan me jaise hcf nikalte the wahi hai
}

// LCM of two numbers
// Striver's Brute force approach
// TC=O(a*b)
// SC=O(1)
int lcm(int a, int b)
{
    int i = 1;
    int maxNum = max(a, b);
    do
    {
        int multiple = i * maxNum;
        if (multiple % a == 0 && multiple % b == 0)
        {
            return multiple;
        }
        i = i + 1;
    } while (1);

    return -1; // This line will never be reached, but it's good practice to have a return statement.
}

// My approach
// TC = O(min(a, b))
// SC = O(1)
int lcmMyApproach(int a, int b)
{
    for (int i = 1; i <= min(a, b); i++)
    {
        if (i * max(a, b) % min(a, b) == 0)
        {
            return i * max(a, b);
        }
    }
}

// Optimal approach using GCD
// TC = O(log(min(a, b)))
// SC = O(1)
int lcmOptimal(int a, int b)
{
    return ((a * b) / gcdEuclidean(a, b)); // LCM(a, b) = (a * b) / GCD(a, b)
}

// Divisors of a number
// TC = O(sqrt(n))
// SC = O(1)
vector<int> getDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    cout << reverseNumber(-12345);
    return 0;
}