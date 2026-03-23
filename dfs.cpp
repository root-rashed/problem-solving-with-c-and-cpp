#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g_node; // Global adjacency list

// Function to perform DFS
void DFS(int start, int node) {
    vector<bool> visited(node + 1, false);
    stack<int> s;
    visited[start] = true;
    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << " ";

        // Push adjacent nodes in reverse order for correct DFS order
        for (int i = g_node[v].size() - 1; i >= 0; i--) {
            if (!visited[g_node[v][i]]) {
                visited[g_node[v][i]] = true;
                s.push(g_node[v][i]);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 5; // Number of nodes
    g_node.resize(nodes); // Resize global adjacency list

    // Adding edges (Directed Graph)
    g_node[0].push_back(1);
    g_node[0].push_back(2);
    g_node[1].push_back(2);
    g_node[2].push_back(3);
    g_node[3].push_back(4);
    g_node[4].push_back(5);
    g_node[4].push_back(7);
    g_node[5].push_back(6);
    g_node[6].push_back(7);
    g_node[6].push_back(4);

    int start_node;
    cout << "Enter the start node: ";
    cin >> start_node;

    // Run DFS from the chosen start node
    DFS(start_node, nodes);

    return 0;
}
