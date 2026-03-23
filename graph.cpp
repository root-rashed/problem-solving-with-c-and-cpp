#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes = 5;
    vector<vector<pair<char, int>>> graph(nodes);
    graph[0].push_back({'D', 60});
    graph[0].push_back({'C', 12});
    graph[1].push_back({'A', 10});
    graph[2].push_back({'B', 20});
    graph[2].push_back({'D', 32});
    graph[4].push_back({'A', 7});

    cout << "Weight graph representation (adjacency list):\n";
    for (int i = 0; i < nodes; i++)
    {
        cout << "Node " << char('A' + i) << "->";
        for (auto neighbor : graph[i])
        {
            cout << "(" << neighbor.first << ",weight " << neighbor.second << ")";
        }
        cout << endl;
    }
    return 0;
}