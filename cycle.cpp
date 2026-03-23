#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g_node;     // Adjacency list
vector<int> flag;               // -1: unvisited, 0: in recursion stack, 1: done
vector<int> parent;             // To trace cycle path
bool cycle_found = false;


// Print cycle in the format: x y z x
void printCycle(int start, int end) {
    vector<int> cycle;
    int curr = end;
    cycle.push_back(curr);
    while (curr != start) {
        curr = parent[curr];
        cycle.push_back(curr);
    }
    reverse(cycle.begin(), cycle.end());
    cycle.push_back(start); // Close the loop

    cout << "The graph has a cycle:\nCycle: ";
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << endl;
}



// DFS function with cycle detection
void DFS(int u) {
    flag[u] = 0; // Node is in recursion stack

    for (int v : g_node[u]) {
        if (flag[v] == -1) {
            parent[v] = u;
            DFS(v);
            if (cycle_found) return;
        } else if (flag[v] == 0) {
            // Found a cycle (back edge)
            cycle_found = true;
            printCycle(v, u);
            return;
        }
    }

    flag[u] = 1; // Node is fully explored
}



int main() {
    int nodes = 5;
    g_node.resize(nodes + 1);
    flag.assign(nodes + 1, -1);
    parent.assign(nodes + 1, -1);


    // Sample graph with cycle: 2 -> 4 -> 5 -> 2
    g_node[1].push_back(2);
    g_node[1].push_back(3);
    g_node[2].push_back(3);
    g_node[2].push_back(4);
    g_node[4].push_back(5);
    g_node[5].push_back(2);

    for (int i = 1; i <= nodes; i++) {
        if (flag[i] == -1) {
            DFS(i);
            if (cycle_found) break;
        }
    }

    if (!cycle_found) {
        cout << "The graph has no cycle." << endl;
    }

    return 0;
}
