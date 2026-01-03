#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    cin >> rows >> cols;

    // Original grid (1-indexed)
    vector<vector<long long>> grid(rows + 1, vector<long long>(cols + 1, 0));

    // Prefix sum array
    vector<vector<long long>> prefix(rows + 1, vector<long long>(cols + 1, 0));

    // Read grid
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cin >> grid[i][j];
        }
    }

    // Build 2D prefix sums
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            prefix[i][j] =
                grid[i][j]
              + prefix[i - 1][j]
              + prefix[i][j - 1]
              - prefix[i - 1][j - 1];
        }
    }

    int queries;
    cin >> queries;

    while (queries--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        long long rectangleSum =
            prefix[r2][c2]
          - prefix[r1 - 1][c2]
          - prefix[r2][c1 - 1]
          + prefix[r1 - 1][c1 - 1];

        cout << rectangleSum << "\n";
    }

    return 0;
}
