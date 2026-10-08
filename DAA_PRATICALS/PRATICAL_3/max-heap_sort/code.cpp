
#include <iostream>
using namespace std;

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < n && arr[left] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[left];
                arr[left] = temp;
            }

            if (right < n && arr[right] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[right];
                arr[right] = temp;
            }
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};

    int n = 5;

    heap_sort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}