#include <bits/stdc++.h>
using namespace std;

const int MAX = 12;  // Total substations S1 to S12
const int INF = 1e9; // Large value for initial key values

// Map index 0-11 to S1 to S12
char getNode(int i)
{
    return 'A' + i; // S1 -> A, S2 -> B, ..., S12 -> L
}


int main()
{
    // Adjacency matrix representing the graph
    int adj[MAX][MAX] = {
        // S1  S2  S3  S4  S5  S6  S7  S8  S9  S10 S11 S12
        {0, 4, 6, 10, 0, 0, 0, 0, 0, 0, 0, 0},  // S1
        {4, 0, 5, 0, 7, 8, 0, 0, 0, 0, 0, 0},   // S2
        {6, 5, 0, 3, 0, 6, 9, 0, 0, 0, 0, 0},   // S3
        {10, 0, 3, 0, 0, 0, 11, 4, 0, 0, 0, 0}, // S4
        {0, 7, 0, 0, 0, 2, 0, 0, 8, 0, 0, 0},   // S5
        {0, 8, 6, 0, 2, 0, 1, 0, 0, 9, 0, 0},   // S6
        {0, 0, 9, 11, 0, 1, 0, 3, 0, 0, 5, 0},  // S7
        {0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 6, 7},   // S8
        {0, 0, 0, 0, 8, 0, 0, 0, 0, 4, 0, 10},  // S9
        {0, 0, 0, 0, 0, 9, 0, 0, 4, 0, 2, 0},   // S10
        {0, 0, 0, 0, 0, 0, 5, 6, 0, 2, 0, 3},   // S11
        {0, 0, 0, 0, 0, 0, 0, 7, 10, 0, 3, 0}   // S12
    };


    int key[MAX];             // Minimum weight to connect to MST
    int parent[MAX];          // Store MST connections
    bool inMST[MAX] = {0};    // Track visited nodes
    vector<int> visitedOrder; // To print order of visitation

    // Initialization
    for (int i = 0; i < MAX; ++i)
    {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0; // Start from S1 (index 0)
    int totalCost = 0;

    cout << "The arbitrary root is selected as S1.\n";
    cout << "Prim's Algorithm Execution:\n\n";

    for (int count = 0; count < MAX; ++count)
    {
        int u = -1;
        int minKey = INF;

        // Find the node with the smallest key not in MST yet
        for (int v = 0; v < MAX; ++v)
        {
            if (!inMST[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;
        visitedOrder.push_back(u);

        // Display step-by-step process
        if (parent[u] != -1)
        {
            cout << "Step " << count << ": ";
            cout << getNode(parent[u]) << " -> " << getNode(u)
                 << " = " << adj[parent[u]][u] << " added to MST\n";
            totalCost += adj[parent[u]][u];
        }
        else
        {
            cout << "Step 0: Start from root node " << getNode(u) << "\n";
        }

        // Show visited nodes
        cout << "Visited Nodes: { ";
        for (int node : visitedOrder)
            cout << getNode(node) << " ";
        cout << "}\n\n";

        // Update keys and parent for adjacent vertices
        for (int v = 0; v < MAX; ++v)
        {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }


    // Final MST Output
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < MAX; ++i)
    {
        cout << getNode(parent[i]) << " - " << getNode(i)
             << " = " << adj[parent[i]][i] << endl;
    }
    cout << "Total Cost of MST: " << totalCost << " lakh Taka\n";

    return 0;
}
