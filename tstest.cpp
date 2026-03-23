#include <bits/stdc++.h>
using namespace std;

// Display the graph as an adjacency list
void graph_output(vector<int> graph[], int node)
{
    for (int i = 0; i < node; i++)
    {
        cout << (char)(i + 'A'); // Convert integer to letter
        for (int neighbor : graph[i])
        {
            cout << " -> " << (char)(neighbor + 'A'); // Convert integer to letter
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
    int nodes = 9; // Nodes 0 to 8 (representing A to I)
    vector<int> graph[nodes];

    // Adding directed edges based on the provided graph
    graph[0].push_back(1); // A → B
    graph[1].push_back(4); // B → E
    graph[2].push_back(1); // C → B
    graph[3].push_back(0); // D → A
    graph[3].push_back(6); // D → G
    graph[4].push_back(3); // E → D
    graph[4].push_back(5); // E → F
    graph[4].push_back(7); // E → H
    graph[5].push_back(8); // F → I
    graph[6].push_back(4); // G → E
    graph[7].push_back(6); // H → G
    graph[7].push_back(5); // H → F
    graph[8].push_back(7); // I → H

    // Output the graph
    cout << "Graph Adjacency List:\n";
    graph_output(graph, nodes);

    // Perform topological sort
    vector<int> sorted_order = topologicalSort(graph, nodes);

    // Output the topological sort
    cout << "\nTopological Sort Order:\n";
    for (int node : sorted_order)
    {
        cout << (char)(node + 'A') << " "; // Convert integer to letter
    }
    cout << endl;

    return 0;
}
