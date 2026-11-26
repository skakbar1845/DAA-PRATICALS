
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int a[10][10];

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int minCost = 99999;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i != j)
            {
                int cost = a[0][i] + a[i][j] + a[j][0];

                if (cost < minCost)
                {
                    minCost = cost;
                }
            }
        }
    }

    cout << "Minimum cost = " << minCost;

    return 0;
}
