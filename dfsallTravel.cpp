#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<string, vector<pair<string, int>>> &graph, string node, string target, vector<string> &path, unordered_set<string> &visited, int weight, vector<pair<vector<string>, int>> &all_paths)
{
    path.push_back(node);
    visited.insert(node);

    if (node == target)
    {
        all_paths.push_back({path, weight});
    }
    else
    {
        for (auto &neighbor : graph[node])
        {
            if (!visited.count(neighbor.first))
            {
                dfs(graph, neighbor.first, target, path, visited, weight + neighbor.second, all_paths);
            }
        }
    }
    path.pop_back();
    visited.erase(node);
}

int main()
{
    unordered_map<string, vector<pair<string, int>>> graph = {
        {"E1", {{"E3", 4}, {"E2", 8}}},
        {"E2", {{"E1", 8}, {"E4", 5}, {"E5", 9}}},
        {"E3", {{"E1", 4}, {"E4", 6}, {"E6", 7}}},
        {"E4", {{"E3", 6}, {"E2", 5}, {"E7", 10}}},
        {"E5", {{"E2", 6}, {"E7", 4}, {"E9", 12}}},
        {"E6", {{"E3", 7}, {"E8", 5}}},
        {"E7", {{"E4", 10}, {"E5", 4}, {"E9", 6}}},
        {"E8", {{"E6", 5}, {"E9", 3}}},
        {"E9", {{"E5", 12}, {"E7", 6}, {"E8", 3}}}};

    string start = "E1", target = "E9";
    vector<string> path;
    unordered_set<string> visited;
    vector<pair<vector<string>, int>> all_paths;

    dfs(graph, start, target, path, visited, 0, all_paths);

    // print all paths with travel times
    cout << "All paths from " << start << " to " << target << " with travel times:\n";
    for (auto &p : all_paths)
    {
        for (size_t i = 0; i < p.first.size(); i++)
        {
            cout << p.first[i] << (i == p.first.size() - 1 ? " " : " -> ");
        }
        cout << "   | Travel times: " << p.second << "\n";
    }

    return 0;
}
