#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;            // Original graph
vector<vector<int>> transposeGraph;   // Transposed graph
vector<bool> visited;
stack<int> finishStack;

// DFS to fill finishing times
void DFS1(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v])
            DFS1(v);
    }
    finishStack.push(u);
}

// DFS on transposed graph to find SCC
void DFS2(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : transposeGraph[u]) {
        if (!visited[v])
            DFS2(v, component);
    }
}

int main() {
    int nodes = 9; // Let's use nodes A(0) to I(8)
    graph.resize(nodes);
    transposeGraph.resize(nodes);

    // Edges from the original question (A=0, B=1, ..., I=8)
    graph[0].push_back(1);     // A → B
    graph[1].push_back(4);     // B → E
    graph[2].push_back(1);     // C → B
    graph[3].push_back(0);     // D → A
    graph[3].push_back(6);     // D → G
    graph[4].push_back(3);     // E → D
    graph[4].push_back(5);     // E → F
    graph[4].push_back(7);     // E → H
    graph[5].push_back(8);     // F → I
    graph[5].push_back(2);     // F → C
    graph[6].push_back(4);     // G → E
    graph[7].push_back(6);     // H → G
    graph[7].push_back(5);     // H → F
    graph[8].push_back(7);     // I → H

    // Step 1: DFS to get finishing order
    visited.assign(nodes, false);
    for (int i = 0; i < nodes; ++i) {
        if (!visited[i])
            DFS1(i);
    }

    // Step 2: Transpose the graph
    for (int u = 0; u < nodes; ++u) {
        for (int v : graph[u]) {
            transposeGraph[v].push_back(u);
        }
    }

    // Step 3: DFS in reverse finishing order on transposed graph
    visited.assign(nodes, false);
    int scc_count = 0;

    cout << "Strongly Connected Components (SCCs):\n";
    while (!finishStack.empty()) {
        int u = finishStack.top();
        finishStack.pop();

        if (!visited[u]) {
            vector<int> component;
            DFS2(u, component);
            scc_count++;

            // Optional: sort for consistent output
            sort(component.begin(), component.end());

            cout << "SCC " << scc_count << ": ";
            for (int node : component)
                cout << char('A' + node) << " ";
            cout << "\n";
        }
    }

    return 0;
}
