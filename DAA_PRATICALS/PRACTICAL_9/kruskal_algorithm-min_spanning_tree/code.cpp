
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edges;

    cout << "Enter u, v and weight:\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int parent[100];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    cout << "Minimum Spanning Tree:\n";

    for (auto e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        int a = u, b = v;

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b)
        {
            cout << u << " - " << v << " : " << w << endl;

            parent[a] = b;
            cost += w;
            count++;
        }

        if (count == V - 1)
            break;
    }

    if (count == V - 1)
        cout << "Total Cost = " << cost;
    else
        cout << "Graph is not connected.";

    return 0;
}
