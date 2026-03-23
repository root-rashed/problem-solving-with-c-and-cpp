#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
const int N = 12;

// Helper function to print a matrix
void printMatrix(const string &title, int dist[N][N])
{
    cout << title << "\n\n  ";
    for (int i = 0; i < N; ++i)
        cout << char('A' + i) << " ";
    cout << "\n";
    for (int i = 0; i < N; ++i)
    {
        cout << char('A' + i) << " ";
        for (int j = 0; j < N; ++j)
        {
            if (dist[i][j] == INF)
                cout << "∞ ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


// Recursive path printer
void printPath(int i, int j, int next[N][N])
{
    if (next[i][j] == -1)
    {
        cout << "No path";
        return;
    }

    vector<int> path;
    while (i != j)
    {
        path.push_back(i);
        i = next[i][j];
    }

    path.push_back(j);
    for (size_t k = 0; k < path.size(); ++k)
    {
        cout << char('A' + path[k]);
        if (k + 1 < path.size())
            cout << " -> ";
    }
}



// Floyd-Warshall with path reconstruction
void floydWarshall(int dist[N][N])
{
    int next[N][N];
    // Initialize next matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            next[i][j] = (dist[i][j] == INF || i == j) ? -1 : j;

    // Print input matrix
    printMatrix("Initial Distance Matrix (Input):", dist);

    // ********* Main Floyd-Warshall ***********
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
        printMatrix("Final Distance Matrix (After each Floyd-Warshall):", dist);
    }


    // Print final matrix
    printMatrix("Distance Matrix (After Floyd-Warshall):", dist);
    // Print all shortest paths
    cout << "All-Pairs Shortest Paths:\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j)
            {
                cout << char('A' + i) << " -> " << char('A' + j) << ": ";
                if (dist[i][j] == INF)
                    cout << "No path\n";
                else
                {
                    cout << "Cost = " << dist[i][j] << ", Path = ";
                    printPath(i, j, next);
                    cout << "\n";
                }
            }
}



int main()
{
    int dist[N][N] = {
        {0, 8, INF, INF, INF, INF, INF, 4, 1, 2, INF, 6},      // Dhaka=A
        {8, 0, INF, INF, 9, 5, INF, INF, INF, INF, INF, 2},    // Chittagong=B
        {INF, INF, 0, INF, INF, 4, 7, INF, INF, INF, 3, INF},  // Khulna=C
        {INF, INF, 7, 0, 10, INF, 6, INF, INF, INF, INF, INF}, // Rajshahi=D
        {INF, 9, INF, INF, 0, INF, 10, 5, INF, INF, INF, INF}, // Sylhet=E
        {7, 5, 4, INF, INF, 0, INF, INF, INF, INF, INF, INF},  // Barishal+F
        {INF, INF, INF, 6, INF, INF, 0, 3, 6, INF, INF, INF},  // Rangpur=G
        {4, INF, INF, INF, 5, INF, 3, 0, INF, INF, INF, INF},  // Mymensingh=H
        {1, INF, INF, INF, INF, INF, 6, INF, 0, INF, 9, INF},  // Gazipur=I
        {2, INF, INF, INF, INF, 7, INF, INF, INF, 0, INF, 3},  // Nayayanganj=J
        {INF, INF, 3, 12, INF, INF, INF, INF, 9, INF, 0, INF}, // Jessore=K
        {6, 2, INF, INF, INF, INF, INF, INF, INF, 3, INF, 0}   // Comilla=L
    };

    floydWarshall(dist);
    return 0;
}
