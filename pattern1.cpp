#include <iostream>
using namespace std;

// Function to print the upper half of the pattern
void printUpperHalf(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << "*";
        // Print spaces between stars (skip for first row)
        if (i != 1)
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print the lower half of the pattern
void printLowerHalf(int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << "*";
        // Print spaces between stars (skip for last row)
        if (i != 1)
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows for upper half: ";
    cin >> n;

    // Input validation
    if (n < 1)
    {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    printUpperHalf(n);
    printLowerHalf(n);

    return 0;
}
