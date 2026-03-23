#include <bits/stdc++.h>
using namespace std;

// Define constant for the number of substations
const int MAX = 12;
// Disjoint Set Union (DSU) parent array
int parent[MAX];


// Initializes each substation as its own parent (used in DSU)
void makeSet()
{
    for (int i = 0; i < MAX; i++)
        parent[i] = i; // Each node is initially its own parent
}

// Finds the representative of the set that element 'v' belongs to
// Applies path compression to optimize future calls
int findSet(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]); // Path compression
}


// Unites two sets that contain elements 'a' and 'b'
// Ensures they belong to different sets to avoid cycles
void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a; // Merge sets by pointing b's root to a's root
}



// Prints the list of visited substations in alphabetical order
void printVisited(const vector<int> &visited)
{
    cout << "Visited array, v = {";
    for (size_t i = 0; i < visited.size(); ++i)
    {
        cout << char('A' + visited[i]); // Convert index to letter (e.g., 0 = A = S1)
        if (i != visited.size() - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}



// Kruskal's Algorithm: Finds Minimum Spanning Tree (MST)
void kruskal(int adj[MAX][MAX])
{
    vector<tuple<int, int, int>> edges; // Stores all edges as (weight, from, to)

    // Extract edges from the adjacency matrix (avoid duplicate edges using i < j)
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (adj[i][j] != 0)
            {
                edges.push_back({adj[i][j], i, j}); // Add valid edge
            }
        }
    }

    // Sort all edges based on their weight (in ascending order)
    sort(edges.begin(), edges.end());

    // Initialize DSU for all substations
    makeSet();

    vector<pair<int, int>> mst; // To store the final MST edges
    vector<int> visited;        // To keep track of visited substations
    int totalCost = 0;          // Total cost of building the MST
    int step = 1;               // Step counter for display

    // Start Kruskal’s logic
    cout << "Then, construct a forest of the given graph on a single plane.\n";
    cout << "From the list of sorted edge costs, select the least cost edge and add it onto the forest in output graph.\n\n";

    for (auto edge : edges)
    {
        int w = get<0>(edge); // weight (cost)
        int u = get<1>(edge); // from substation
        int v = get<2>(edge); // to substation

        // If u and v are in different sets, they can be connected safely (no cycle)
        if (findSet(u) != findSet(v))
        {
            unionSets(u, v);       // Merge the sets
            mst.push_back({u, v}); // Add edge to MST
            totalCost += w;        // Add cost to total

            // Mark substations as visited if not already
            if (find(visited.begin(), visited.end(), u) == visited.end())
                visited.push_back(u);
            if (find(visited.begin(), visited.end(), v) == visited.end())
                visited.push_back(v);

            // Print step-by-step progress
            cout << "Step " << step++ << ": Add edge "
                 << char('A' + u) << " -> " << char('A' + v)
                 << " = " << w << " lakhs" << endl;

            cout << "Minimum cost = " << totalCost << " lakhs, ";
            printVisited(visited);
            cout << endl;
        }
    }



    // Final Output: Display all MST edges and total cost
    cout << "Minimum Spanning Tree Edges:\n";
    for (auto edge : mst)
    {
        cout << "(" << char(edge.first + 'A') << ", " << char(edge.second + 'A') << ")\n";
    }
    cout << "Total Cost: " << totalCost << " lakhs" << endl;
}




// Main function
int main()
{
    // Adjacency matrix based on provided substation connections and costs (in lakhs of taka)
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

    // Run Kruskal's algorithm to compute MST
    kruskal(adj);

    return 0;
}
