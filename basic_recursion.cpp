#include <bits/stdc++.h>
using namespace std;

int nNumbersSum(int n)
{
    if (n == 0)
        return 0;
    return n + nNumbersSum(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << nNumbersSum(n);
    return 0;
}