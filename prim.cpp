#include <bits/stdc++.h>
using namespace std;

const int MAX = 12;  // Total substations: S1 to S12
const int INF = 1e9; // Representation of infinity for initial key values

// Converts node index (0–11) to substation name S1–S12
string getSubstationName(int index)
{
    return "S" + to_string(index + 1); // 0 becomes S1, 1 becomes S2, ..., 11 becomes S12
}

int main()
{
    // Adjacency matrix based on provided SmartGrid connection costs (in lakh Taka)
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

    int key[MAX];          // Minimum cost to add node to MST
    int parent[MAX];       // Store MST structure
    bool inMST[MAX] = {0}; // Track nodes already in MST
    vector<int> visitedOrder;

    // Initialize all nodes' key values to INF and no parents
    for (int i = 0; i < MAX; ++i)
    {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0; // Start Prim's algorithm from S1 (index 0)
    int totalCost = 0;

    cout << "Prim's Algorithm: Optimizing Electric Line Infrastructure (S1 – S12)\n";
    cout << "Starting from root node: S1\n\n";

    for (int count = 0; count < MAX; ++count)
    {
        int u = -1;
        int minKey = INF;

        // Select the unvisited node with the smallest key value
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

        // Print step of adding node to MST
        if (parent[u] != -1)
        {
            cout << "Step " << count << ": Add edge "
                 << getSubstationName(parent[u]) << " -> " << getSubstationName(u)
                 << " = " << adj[parent[u]][u] << " lakh Taka\n";
            totalCost += adj[parent[u]][u];
        }
        else
        {
            cout << "Step 0: Start at root node " << getSubstationName(u) << "\n";
        }

        // Display visited substations so far
        cout << "Visited Substations: { ";
        for (int node : visitedOrder)
            cout << getSubstationName(node) << " ";
        cout << "}\n\n";

        // Update key and parent for adjacent unvisited substations
        for (int v = 0; v < MAX; ++v)
        {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    // Output final MST structure and total cost
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < MAX; ++i)
    {
        cout << getSubstationName(parent[i]) << " - " << getSubstationName(i)
             << " = " << adj[parent[i]][i] << " lakh Taka\n";
    }

    cout << "Total Minimum Infrastructure Cost: " << totalCost << " lakh Taka\n";

    return 0;
}
