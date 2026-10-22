
#include <iostream>
using namespace std;

int main()
{
    int V, E;
    int d[100][100];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 99999;
        }
    }

    cout << "Enter source, destination and weight:\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        d[u][v] = w;
        d[v][u] = w;
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (d[i][k] != 99999 &&
                    d[k][j] != 99999 &&
                    d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (d[i][j] == 99999)
                cout << "INF ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
