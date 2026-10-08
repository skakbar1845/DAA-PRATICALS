#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};

    int num;

    cout << "Enter number to search: ";
    cin >> num;

    int first = 0;
    int last = 6;

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (num == arr[mid])
        {
            cout << "Element Found";
            break;
        }

        if (num < arr[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    if (first > last)
    {
        cout << "Element Not Found";
    }

    return 0;
}