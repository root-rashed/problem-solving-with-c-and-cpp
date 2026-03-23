#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Edge;

// Topological Sort using DFS
void topoSort(int node, vector<Edge> graph[], vector<bool> &visited, stack<int> &stk)
{
    visited[node] = true;
    for (auto edge : graph[node])
    {
        int next = edge.first;
        if (!visited[next])
        {
            topoSort(next, graph, visited, stk);
        }
    }
    stk.push(node);
}

// Print path using parent array
void printPath(int node, vector<int> &parent)
{
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}

int main()
{
    int nodes = 6; // Number of nodes (0 to 5)
    vector<Edge> graph[nodes];

    // Graph input (Directed Acyclic Graph with weights)
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 2});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 7});
    graph[2].push_back({4, 4});
    graph[2].push_back({5, 8});
    graph[3].push_back({4, -1});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, -2});

    int start;
    cout << "Enter starting node (0 to 5): ";
    cin >> start;

    // Topological sorting
    stack<int> stk;
    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            topoSort(i, graph, visited, stk);
        }
    }

    // Distance and parent arrays
    vector<int> dist(nodes, INT_MAX);
    vector<int> parent(nodes, -1);
    dist[start] = 0;

    // Relax edges in topological order
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        if (dist[u] != INT_MAX)
        {
            for (auto edge : graph[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Print all shortest paths
    cout << "\nShortest paths from node " << start << ":\n";
    for (int i = 0; i < nodes; i++)
    {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX)
        {
            cout << "No path\n";
        }
        else
        {
            cout << "Cost = " << dist[i] << ", Path = ";
            printPath(i, parent);
            cout << endl;
        }
    }

    // Final shortest path to last node
    cout << "\nThe final shortest path is from node " << start << " to node " << (nodes - 1)
         << " with cost ";
    if (dist[nodes - 1] == INT_MAX)
    {
        cout << "infinity (No path exists).\n";
    }
    else
    {
        cout << dist[nodes - 1] << ": ";
        printPath(nodes - 1, parent);
        cout << endl;
    }

    return 0;
}
