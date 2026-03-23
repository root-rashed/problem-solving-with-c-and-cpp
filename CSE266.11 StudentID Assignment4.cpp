#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(vector<int> &d, vector<int> &pi, int s)
{
    int v = d.size();
    for (int i = 1; i < v; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }
    d[s] = 0;
}

bool relax(vector<int> &d, vector<int> &pi, int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}


void print_path(const vector<int> &pi, int s, int des)
{
    stack<int> stk;
    int temp = des;
    while (temp != -1 && temp != s)
    {
        stk.push(temp);
        temp = pi[temp];
    }

    if (temp == -1)
    {
        cout << "No path";
        return;
    }

    cout << s;
    while (!stk.empty())
    {
        cout << " -> " << stk.top();
        stk.pop();
    }
}


void dijkstra(const vector<vector<pair<int, int>>> &graph, int source)
{
    int v = graph.size();
    vector<int> pi(v), d(v);
    vector<bool> visited(v, false);

    initialize_single_source(d, pi, source);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source}); // Fixed: cost from source to itself is 0


    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &[v_adj, w] : graph[u])
        {
            if (relax(d, pi, u, v_adj, w))
            {
                pq.push({d[v_adj], v_adj});
            }
        }
    }

    for (int i = 1; i < v; i++)
    {
        if (i == source)
            continue;
        cout << "Shortest path from " << source << " to " << i << ": ";
        print_path(pi, source, i);
        if (d[i] != INT_MAX)
            cout << "\tCost = " << d[i] << " hours" << endl;
        else
            cout << "\tNo reachable path" << endl;
    }
}


int main()
{
    int nodes = 10;
    vector<vector<pair<int, int>>> graph(nodes + 1); // 1-based indexing

    // Edges from the image - undirected, so add both directions
    graph[1].push_back({2, 6});
    graph[2].push_back({1, 6});

    graph[1].push_back({3, 4});
    graph[3].push_back({1, 4});

    graph[2].push_back({3, 2});
    graph[3].push_back({2, 2});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    graph[2].push_back({6, 10});
    graph[6].push_back({2, 10});

    graph[3].push_back({5, 3});
    graph[5].push_back({3, 3});

    graph[3].push_back({7, 9});
    graph[7].push_back({3, 9});

    graph[4].push_back({5, 1});
    graph[5].push_back({4, 1});

    graph[4].push_back({7, 6});
    graph[7].push_back({4, 6});

    graph[4].push_back({8, 8});
    graph[8].push_back({4, 8});

    graph[5].push_back({6, 5});
    graph[6].push_back({5, 5});

    graph[5].push_back({9, 7});
    graph[9].push_back({5, 7});

    graph[6].push_back({8, 2});
    graph[8].push_back({6, 2});

    graph[6].push_back({10, 4});
    graph[10].push_back({6, 4});

    graph[7].push_back({8, 3});
    graph[8].push_back({7, 3});

    graph[7].push_back({9, 6});
    graph[9].push_back({7, 6});

    graph[8].push_back({9, 5});
    graph[9].push_back({8, 5});

    graph[9].push_back({10, 2});
    graph[10].push_back({9, 2});

    // Run Dijkstra from source node R1 = node 1
    cout << "--- Shortest Paths from Source Node R1 ---" << endl;
    dijkstra(graph, 1);

    return 0;
}
