
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> graph[V];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> visited(V, false);

    // Min-heap: {weight, vertex}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 0});

    int totalCost = 0;
    int edges = 0;

    cout << "\nMinimum Spanning Tree:\n";

    while (!pq.empty() && edges < V - 1)
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        totalCost += weight;

        if (u != 0 || weight != 0)
        {
            cout << "Vertex: " << u
                 << ", Weight: " << weight << endl;
            edges++;
        }

        for (auto neighbour : graph[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;

            if (!visited[v])
                pq.push({w, v});
        }
    }

    if (edges != V - 1)
        cout << "Graph is not connected.\n";
    else
        cout << "Total Cost = " << totalCost << endl;

    return 0;
}
