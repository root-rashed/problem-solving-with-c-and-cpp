#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g_node;  // Adjacency list
vector<bool> visited;        // Global visited
vector<int> recStack;        // Current DFS path
set<vector<int>> all_cycles; // Set to store unique cycles

// Helper to normalize and store cycles to avoid duplicates
void storeCycle(const vector<int> &raw_cycle)
{
    vector<int> cycle = raw_cycle;

    // Normalize: rotate to smallest element to get canonical form
    auto it = min_element(cycle.begin(), cycle.end());
    rotate(cycle.begin(), it, cycle.end());

    all_cycles.insert(cycle);
}

void DFS(int u)
{
    visited[u] = true;
    recStack.push_back(u);

    for (int v : g_node[u])
    {
        auto it = find(recStack.begin(), recStack.end(), v);
        if (it != recStack.end())
        {
            // Found a cycle: extract from v to current node
            vector<int> cycle(it, recStack.end());
            storeCycle(cycle);
        }
        else if (!visited[v])
        {
            DFS(v);
        }
    }

    recStack.pop_back();
}

int main()
{
    int nodes = 9; // Nodes A–I => 0–8
    g_node.resize(nodes);
    visited.assign(nodes, false);

    // Graph edges based on your input
    g_node[0] = {1};       // A → B
    g_node[1] = {4};       // B → E
    g_node[2] = {1};       // C → B
    g_node[3] = {0, 6};    // D → A, G
    g_node[4] = {3, 5, 7}; // E → D, F, H
    g_node[5] = {8, 2};    // F → I, C
    g_node[6] = {4};       // G → E
    g_node[7] = {6, 5};    // H → G, F
    g_node[8] = {7};       // I → H

    // Run DFS from each node
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }

    // Output the detected cycles
    if (all_cycles.empty())
    {
        cout << "No cycles found.\n";
    }
    else
    {
        int count = 1;
        for (const auto &cycle : all_cycles)
        {
            cout << "Cycle " << count++ << ": ";
            for (size_t i = 0; i < cycle.size(); i++)
            {
                cout << char('A' + cycle[i]);
                if (i + 1 < cycle.size())
                    cout << " ";
            }
            cout << " " << char('A' + cycle[0]) << " " << endl;
        }
    }

    return 0;
}
