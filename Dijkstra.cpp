#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(vector<int>& d, vector<int>& pi, int s)
{
    int v = d.size();
    for (int i = 0; i < v; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }
    d[s] = 0;
}


bool relax(vector<int>& d, vector<int>& pi, int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}


void print_path(const vector<int>& pi, int s, int des)
{
    stack<int> stk;
    int temp = des;
    while (temp != -1 && temp != s)
    {
        stk.push(temp);
        temp = pi[temp];
    }

    cout << s;
    while (!stk.empty())
    {
        cout << " -> " << stk.top();
        stk.pop();
    }
}


void dijkstra(const vector<vector<pair<int, int>>>& graph, int source)
{
    int v = graph.size();
    vector<int> pi(v), d(v);
    vector<bool> visited(v, false);

    initialize_single_source(d, pi, source);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v_adj, w] : graph[u])
        {
            if (relax(d, pi, u, v_adj, w))
            {
                pq.push({d[v_adj], v_adj});
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (i == source) continue;
        cout << "Shortest path from " << source << " to " << i << ": ";
        print_path(pi, source, i);
        cout << "\tCost = " << d[i] << endl;
    }
}



int main()
{
    int nodes = 6;
    vector<vector<pair<int, int>>> graph(nodes);

    // Undirected Weighted Graph
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 4});

    graph[1].push_back({0, 4});
    graph[1].push_back({2, 2});

    graph[2].push_back({0, 4});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 1});
    graph[2].push_back({5, 6});

    graph[3].push_back({2, 3});
    graph[3].push_back({5, 2});

    graph[4].push_back({2, 1});
    graph[4].push_back({5, 3});

    graph[5].push_back({3, 2});
    graph[5].push_back({2, 6});
    graph[5].push_back({4, 3});

    // Run Dijkstra from source node 0 only
    cout << "--- Shortest Paths from Source Node 0 ---" << endl;
    dijkstra(graph, 0);

    return 0;
}
