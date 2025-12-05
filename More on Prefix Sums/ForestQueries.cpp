#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    char C;
    cin >> N >> Q;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> C;
            if (C == '.') {
                grid[i][j] = 0;
            }
            if (C == '*') {
                grid[i][j] = 1;
            }
        }
    }
    vector<vector<int>> pre(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    int sr, er, sc, ec;
    for (int i = 0; i < Q; ++i) {
        cin >> sr >> sc >> er >> ec;
        cout << pre[er][ec] - pre[sr - 1][ec] - pre[er][sc - 1] + pre[sr - 1][sc - 1] << '\n';
    }
}