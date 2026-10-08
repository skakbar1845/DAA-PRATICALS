#include <iostream>
using namespace std;

// Iterative method
int factorial_iterative(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive method
int factorial_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial_recursive(n - 1);
    }
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Display results
    cout << "Factorial using Iterative method: "
         << factorial_iterative(n) << endl;

    cout << "Factorial using Recursive method: "
         << factorial_recursive(n) << endl;

    return 0;
}