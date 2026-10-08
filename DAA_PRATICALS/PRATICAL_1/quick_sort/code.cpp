#include <iostream>
using namespace std;

void quick_sort(int arr[], int n)
{
    if (n <= 1)
        return;

    int pivot = arr[0];

    int left[100];
    int right[100];

    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= pivot)
        {
            left[l] = arr[i];
            l++;
        }
        else
        {
            right[r] = arr[i];
            r++;
        }
    }

    quick_sort(left, l);
    quick_sort(right, r);

    int k = 0;

    for (int i = 0; i < l; i++)
    {
        arr[k] = left[i];
        k++;
    }

    arr[k] = pivot;
    k++;

    for (int i = 0; i < r; i++)
    {
        arr[k] = right[i];
        k++;
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quick_sort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}