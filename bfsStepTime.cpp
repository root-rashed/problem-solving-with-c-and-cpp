#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and find the shortest path in terms of steps
void bfs_shortest_path(unordered_map<string, vector<pair<string, int>>>& graph, string start, string target) {
    queue<vector<string>> q;
    unordered_map<string, int> travel_time;
    unordered_map<string, int> steps;
    unordered_set<string> visited;
    q.push({start});
    travel_time[start] = 0;
    steps[start] = 0;
    visited.insert(start);

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();
        string node = path.back();

        if (node == target) {
            cout << "Shortest path (by edges) from " << start << " to " << target << ":\n";
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i] << (i == path.size() - 1 ? " " : " -> ");
            }
            cout << "\nTotal steps: " << steps[node] << "; Total travel time: " << travel_time[node] << "\n";
            return;
        }

        for (const auto& neighbor : graph[node]) {
            if (!visited.count(neighbor.first)) {
                vector<string> new_path = path;
                new_path.push_back(neighbor.first);
                q.push(new_path);
                travel_time[neighbor.first] = travel_time[node] + neighbor.second;
                steps[neighbor.first] = steps[node] + 1;
                visited.insert(neighbor.first);
            }
        }
    }
    cout << "No path found from " << start << " to " << target << "\n";
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graph = {
        {"E1", {{"E3", 4}, {"E2", 8}}},
        {"E2", {{"E1", 8}, {"E4", 5}, {"E5", 9}}},
        {"E3", {{"E1", 4}, {"E4", 6}, {"E6", 7}}},
        {"E4", {{"E3", 6}, {"E2", 5}, {"E7", 10}}},
        {"E5", {{"E2", 6}, {"E7", 4}, {"E9", 12}}},
        {"E6", {{"E3", 7}, {"E8", 5}}},
        {"E7", {{"E4", 10}, {"E5", 4}, {"E9", 6}}},
        {"E8", {{"E6", 5}, {"E9", 3}}},
        {"E9", {{"E5", 12}, {"E7", 6}, {"E8", 3}}}
    };

    string start = "E1", target = "E9";
    bfs_shortest_path(graph, start, target);

    return 0;
}