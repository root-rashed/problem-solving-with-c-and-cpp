#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g_node;      // Original graph
vector<vector<int>> g_transpose; // Transposed graph
vector<bool> visited;
stack<int> finishStack;
unordered_map<char, int> nodeIndex;
unordered_map<int, char> indexNode;

// First DFS to compute finishing times
void DFS1(int u)
{
    visited[u] = true;
    for (int v : g_node[u])
    {
        if (!visited[v])
            DFS1(v);
    }
    finishStack.push(u);
}

// Second DFS on the transposed graph
void DFS2(int u, vector<int> &component)
{
    visited[u] = true;
    component.push_back(u);
    for (int v : g_transpose[u])
    {
        if (!visited[v])
            DFS2(v, component);
    }
}

int main()
{
    // Directly use 0-8 for nodes A-I
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int n = 9;

    g_node.resize(n);
    g_transpose.resize(n);

    // Map characters to indices
    for (int i = 0; i < n; i++)
    {
        nodeIndex[nodes[i]] = i;
        indexNode[i] = nodes[i];
    }

    // Adding edges based on your graph
    g_node[nodeIndex['A']].push_back(nodeIndex['B']);
    g_node[nodeIndex['B']].push_back(nodeIndex['E']);
    g_node[nodeIndex['C']].push_back(nodeIndex['B']);
    g_node[nodeIndex['D']].push_back(nodeIndex['A']);
    g_node[nodeIndex['D']].push_back(nodeIndex['G']);
    g_node[nodeIndex['E']].push_back(nodeIndex['D']);
    g_node[nodeIndex['E']].push_back(nodeIndex['F']);
    g_node[nodeIndex['E']].push_back(nodeIndex['H']);
    g_node[nodeIndex['F']].push_back(nodeIndex['I']);
    g_node[nodeIndex['G']].push_back(nodeIndex['E']);
    g_node[nodeIndex['H']].push_back(nodeIndex['G']);
    g_node[nodeIndex['H']].push_back(nodeIndex['F']);
    g_node[nodeIndex['I']].push_back(nodeIndex['H']);

    // Step 1: First DFS to get finishing times
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS1(i);
    }

    // Step 2: Transpose the graph
    for (int u = 0; u < n; u++)
    {
        for (int v : g_node[u])
        {
            g_transpose[v].push_back(u);
        }
    }

    // Step 3: Second DFS in reverse finishing order
    visited.assign(n, false);
    cout << "Strongly Connected Components:\n";
    while (!finishStack.empty())
    {
        int u = finishStack.top();
        finishStack.pop();

        if (!visited[u])
        {
            vector<int> component;
            DFS2(u, component);

            // Output SCC using characters
            for (int node : component)
                cout << indexNode[node] << " ";
            cout << endl;
        }
    }

    return 0;
}
