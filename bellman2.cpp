#include <bits/stdc++.h>
using namespace std;

// Mapping node index to character A-J (1-10)
char node_name(int idx)
{
    return 'A' + idx - 1;
}

// Initialize single source
void initialize_single_source(int d[], int pi[], int v, int s)
{
    for (int i = 1; i <= v; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }
    d[s] = 0;
}

// Relax function
bool relax(int d[], int pi[], int u, int v, int w)
{
    if (d[u] != INT_MAX && d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}

// Print path recursively
void print_path(int pi[], int s, int des)
{
    if (des == s)
    {
        cout << node_name(s);
        return;
    }
    if (pi[des] == -1)
    {
        cout << "No path";
        return;
    }
    print_path(pi, s, pi[des]);
    cout << "->" << node_name(des);
}

// Bellman-Ford algorithm
void bellman_ford(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n + 1];
    int d[n + 1];

    initialize_single_source(d, pi, n, s);

    // Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto edge : g[u])
            {
                int v = edge.first;
                int w = edge.second;
                relax(d, pi, u, v, w);
            }
        }
    }

    // Negative cycle detection
    for (int u = 1; u <= n; u++)
    {
        for (auto edge : g[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (d[u] != INT_MAX && d[v] > d[u] + w)
            {
                cout << "\nNegative cycle detected involving edge "
                     << node_name(u) << " -> " << node_name(v) << " with weight " << w << endl;
                return;
            }
        }
    }

    // Print results
    cout << "\n--- Shortest Paths from Source Node " << node_name(s) << " ---\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << node_name(i) << ": Cost = ";
        if (d[i] == INT_MAX)
            cout << "INF, Path: No path\n";
        else
        {
            cout << d[i] << ", Path: ";
            print_path(pi, s, i);
            cout << endl;
        }
    }
}

int main()
{
    int n = 10;  // Nodes R1 to R10 => 1 to 10
    vector<pair<int, int>> adj[n + 1];

    // Original edges
    adj[1].push_back({2, 6});     // R1 -> R2
    adj[1].push_back({3, 4});     // R1 -> R3
    
    adj[2].push_back({3, 2});     // R2 -> R3
    adj[2].push_back({4, 7});     // R2 -> R4
    adj[2].push_back({6, 10});    // R2 -> R6
    
    // adj[3].push_back({5, 3});     // R3 -> R5
    adj[3].push_back({7, 9});     // R3 -> R7
    
    // adj[4].push_back({5, 1});     // R4 -> R5
    adj[4].push_back({7, 6});     // R4 -> R7
    adj[4].push_back({8, 8});     // R4 -> R8
    
    adj[5].push_back({6, 5});     // R5 -> R6
    adj[5].push_back({9, 7});     // R5 -> R9
    
    // adj[6].push_back({8, 2});    // R6 -> R8
    adj[6].push_back({10, 4});    // R6 -> R10
    
    adj[7].push_back({8, 3});     // R7 -> R8
    adj[7].push_back({9, 6});     // R7 -> R9
    
    adj[8].push_back({9, 5});     // R8 -> R9
    
    adj[9].push_back({10, 2});     // R9 -> R10

    // Modifications
    adj[3].push_back({5, 7});     // R3 -> R5 flood delay
    adj[4].push_back({5, -2});    // R4 -> R5 subsidy
    adj[2].push_back({5, 1});     // New air-drop R2 -> R5
    adj[6].push_back({8, 5});     // R6 -> R8 cracked road
    adj[1].push_back({7, 8});     // Shortcut R1 -> R7
    adj[8].push_back({10, 3});    // New route R8 -> R10

    // Negative cycle components
    adj[9].push_back({6, -6});    // R9 -> R6
    adj[8].push_back({9, 5});     // R8 -> R9
    adj[6].push_back({8, 5});     // R6 -> R8
    adj[9].push_back({10, 2});    // R9 -> R10

    // Input and run
    char start_char;
    cout << "Enter starting node (A–J): ";
    cin >> start_char;
    int s = start_char - 'A' + 1;

    bellman_ford(adj, s, n);

    return 0;
}