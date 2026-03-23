#include <bits/stdc++.h>
using namespace std;

const int MAX = 12;
int parent[MAX];

// Converts a node index (0 to 11) to substation label S1 to S12
string getSubstationName(int index)
{
    return "S" + to_string(index + 1);
}

// Initializes each substation as its own parent (for DSU)
void makeSet()
{
    for (int i = 0; i < MAX; i++)
        parent[i] = i;
}

// Finds the representative of a set (with path compression)
int findSet(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

// Unites two sets (used in Kruskal's MST)
void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

// Prints the visited substations
void printVisited(const vector<int> &visited)
{
    cout << "Visited array, V = { ";
    for (size_t i = 0; i < visited.size(); ++i)
    {
        cout << getSubstationName(visited[i]);
        if (i != visited.size() - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

// Kruskal's Algorithm implementation
void kruskal(int adj[MAX][MAX])
{
    vector<tuple<int, int, int>> edges;

    // Collect all edges from the adjacency matrix
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (adj[i][j] != 0)
            {
                edges.push_back({adj[i][j], i, j});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    makeSet();

    vector<pair<int, int>> mst;
    vector<int> visited;
    int totalCost = 0;
    int step = 1;

    cout << "Then, construct a forest of the given graph on a single plane.\n";
    cout << "From the list of sorted edge costs, select the least cost edge and add it onto the forest in output graph.\n\n";

    for (auto edge : edges)
    {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        if (findSet(u) != findSet(v))
        {
            unionSets(u, v);
            mst.push_back({u, v});
            totalCost += w;

            if (find(visited.begin(), visited.end(), u) == visited.end())
                visited.push_back(u);
            if (find(visited.begin(), visited.end(), v) == visited.end())
                visited.push_back(v);

            cout << "Step " << step++ << ": Add edge "
                 << getSubstationName(u) << " -> " << getSubstationName(v)
                 << " = " << w << " lakhs" << endl;

            cout << "Minimum cost = " << totalCost << " lakhs, ";
            printVisited(visited);
            cout << endl;
        }
    }

    // Output the MST edges and total cost
    cout << "Minimum Spanning Tree Edges:\n";
    for (auto edge : mst)
    {
        cout << "(" << getSubstationName(edge.first)
             << ", " << getSubstationName(edge.second) << ")\n";
    }
    cout << "Total Cost: " << totalCost << " lakhs" << endl;
}

// Main function
int main()
{
    int adj[MAX][MAX] = {
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

    kruskal(adj);
    return 0;
}
