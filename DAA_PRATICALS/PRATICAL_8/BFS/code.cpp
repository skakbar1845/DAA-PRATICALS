#include <iostream>
using namespace std;
int main()
{
    int n, e;
    int graph[10][10] = {0};
    int visited[10] = {0};
    int q[10];
    int front = 0;
    int rear = 0;
    cout << "enter no:of vertices :";
    cin >> n;
    cout << "enter no:of edges :";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int src = 0;
    q[rear] = src;
    rear++;
    visited[src] = 1;
    cout << "BSF: ";
    while (front < rear)
    {
        int current = q[front];
        front++;
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear] = i;
                rear++;
            }
        }
    }
    cout << endl;
    return 0;
}