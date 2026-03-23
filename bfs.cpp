#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g_node; // Global adjacency list

// Function to perform BFS
void BFS(int start, int node) {
    vector<bool> visited(node + 1, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < g_node[v].size(); i++) {
            if (!visited[g_node[v][i]]) {
                visited[g_node[v][i]] = true;
                q.push(g_node[v][i]);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 7; // Number of nodes
    g_node.resize(nodes + 1); // Resize global adjacency list

    // Adding edges (Directed Graph)
    g_node[1].push_back(2);
    g_node[1].push_back(3);
    g_node[2].push_back(5);
    g_node[2].push_back(4);
    g_node[2].push_back(1);
    g_node[3].push_back(1);
    g_node[3].push_back(6);
    g_node[4].push_back(2);
    g_node[4].push_back(7);
    g_node[5].push_back(2);
    g_node[5].push_back(6);
    g_node[5].push_back(7);
    g_node[6].push_back(5);
    g_node[6].push_back(7);
    g_node[6].push_back(3);
    g_node[7].push_back(5);
    g_node[7].push_back(4);
    g_node[7].push_back(6);

    int start_node;
    cout << "Enter the start node: ";
    cin >> start_node;

    // Run BFS from the chosen start node
    BFS(start_node, nodes);

    return 0;
}
