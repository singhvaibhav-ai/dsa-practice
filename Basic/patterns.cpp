#include <iostream>
using namespace std;
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1;
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            cout << "*";
            if (j != 0)
                cout << " ";
        }
        cout << endl;
    }
    // Striver's Code
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < n - i + 1; j++)
    //     {
    //         cout << "*";
    //         if (j != n - i)
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
}
void print6(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
            if (j != 2 * i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 2 * i; k++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
            if (j != 2 * (n - i) - 2)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print9(int n)
{
    print7(n);
    print8(n);
}
void print10(int n)
{
    // My Code
    // print2(n);
    // print5(n-1);
    // // for (int i = n - 2; i >= 0; i--)
    // // {
    // //     for (int j = 0; j <= i; j++)
    // //     {
    // //         cout << "*";
    // //         if (j != i)
    // //             cout << " ";
    // //     }
    // //     cout << endl;
    // // }

    // Striver's Code
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print11(int n)
{
    // My Code
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << (i+j+1) % 2;
    //         if (j != i)
    //             cout << " ";
    //     }
    //     cout << endl;
    // }

    // Striver's Code
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            if (j != i)
            {
                cout << " ";
            }
            start = 1 - start;
        }
        cout << endl;
    }
}
void print12(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 0; j--)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num;
            num++;
            if (j != i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print14(int n)
{
    // My Code
    // for (int i = 0; i < n; i++)
    // {
    //     char start = 'A';
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << start;
    //         if (j != i)
    //             cout << " ";
    //         start++;
    //     }
    //     cout << endl;
    // }

    // Striver's Code
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
            if (ch != 'A' + i)
                cout << " ";
        }
        cout << endl;
    }
}
void print15(int n)
{
    // My Code
    // for (int i = 0; i < n; i++)
    // {
    //     char start = 'A';
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         cout << start;
    //         if (j != n - i)
    //             cout << " ";
    //         start++;
    //     }
    //     cout << endl;
    // }

    // Striver's Code
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + n - i - 1; ch++)
        {
            cout << ch;
            if (ch != 'A' + n - 1 - i)
                cout << " ";
        }
        cout << endl;
    }
}
void print16(int n)
{
    // My Code or Striver's Code
    // for (int i = 0; i < n; i++)
    // {
    //     char start = 'A' + i;
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << start;
    //         if (j != i)
    //             cout << " ";
    //     }
    //     cout << endl;
    //     start++;
    // }

    // My code 2
    for (char ch = 'A'; ch <= 'A' + n - 1; ch++)
    {
        for (char j = 'A'; j <= ch; j++)
        {
            cout << ch;
            if (j != ch)
                cout << " ";
        }
        cout << endl;
    }
}
void print17(int n)
{
    // Striver's Code
    for (int i = 0; i < n; i++)
    {
        // Spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // characters
        char ch = 'A';
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
            if (j < i)
                ch++;
            else
                ch--;
        }

        // Spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print18(int n)
{
    // My code
    for (int i = 0; i < n; i++)
    {
        char start = 'A' + n - i - 1;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start++;
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }

    // Striver's Code
    // for (int i = 0; i < n; i++)
    // {
    //     for (char ch = 'E' - i; ch <= 'E'; ch++)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout<<endl;
    // }
}
void print19(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        int stars = i;
        if (i >= n)
            stars = 2 * n - i - 1;
        // Stars
        for (int j = 0; j < n - stars; j++)
        {
            cout << "*";
        }
        // Space
        for (int j = 0; j < 2 * stars; j++)
        {
            cout << " ";
        }

        // Stars
        for (int j = 0; j < n - stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print20(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int stars = i;
        if (i >= n)
            stars = 2 * n - i - 2;
        for (int j = 0; j <= stars; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - stars - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print21(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int j = 0; j < n - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}
void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int num;
        if (i < n)
            num = n - i;
        else
            num = i - n + 2;

        int copyNum = n;

        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (j < n - num)
            {
                cout << copyNum << " ";
                copyNum--;
            }
            else if (j >= n + num - 1)
            {
                copyNum++;
                cout << copyNum << " ";
            }
            else
            {
                cout << num << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cout << "Enter the number of testcases : ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cout << "testcase " << i + 1 << " : ";
        cin >> n;
        print22(n);
        cout << endl;
    }
    return 0;
}