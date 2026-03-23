#include <bits/stdc++.h>
using namespace std;

// Display the graph as an adjacency list
void graph_output(vector<int> graph[], int node)
{
    for (int i = 0; i < node; i++)
    {
        cout << i;
        for (int neighbor : graph[i])
        {
            cout << " -> " << neighbor;
        }
        cout << endl;
    }
}

// DFS for topological sort
void DFS(vector<int> graph[], int i, bool visited[], stack<int> &s)
{
    visited[i] = true;

    for (int next : graph[i])
    {
        if (!visited[next])
        {
            DFS(graph, next, visited, s);
        }
    }

    s.push(i);
}

// Topological sort using DFS
vector<int> topologicalSort(vector<int> graph[], int node)
{
    stack<int> s;
    vector<int> order;
    bool visited[node] = {false};

    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, s);
        }
    }

    while (!s.empty())
    {
        order.push_back(s.top());
        s.pop();
    }

    return order;
}

int main()
{
    int nodes = 6; // Nodes 0 to 5
    vector<int> graph[nodes];

    // Adding directed edges (unweighted)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);

    // Output the graph
    cout << "Graph Adjacency List:\n";
    graph_output(graph, nodes);

    // Perform topological sort
    vector<int> sorted_order = topologicalSort(graph, nodes);

    // Output the topological sort
    cout << "\nTopological Sort Order:\n";
    for (int node : sorted_order)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
