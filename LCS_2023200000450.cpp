#include<bits/stdc++.h>
using namespace std;
void Print_LCS(vector<vector<int>> &b, string x, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 1) {
        Print_LCS(b, x, i - 1, j - 1);
        cout << x[i - 1];
    } else if (b[i][j] == 2) {
        Print_LCS(b, x, i - 1, j);
    } else {
        Print_LCS(b, x, i, j - 1);
    }
}


void LCS_Length(string x, string y) {
    int m = x.size(), n = y.size();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> b(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)

            // 1st condition
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;

            // 2nd condition
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;

            // 3rd condition
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }


    cout << "\nLCS: ";


    Print_LCS(b, x, m, n);
    cout << "\nLength of LCS: " << c[m][n] << endl;
    cout << "Percentage coverage of X: " << (100.0 * c[m][n]) / m << "%\n";
    cout << "Percentage coverage of Y: " << (100.0 * c[m][n]) / n << "%\n";
}



int main() {
    string x = "AGGTABACGTTAC";
    string y = "GXTXAYBCGTCA";
    LCS_Length(x, y);
    return 0;
}