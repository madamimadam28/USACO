/* 
Link for problem: https://atcoder.jp/contests/agc015/tasks/agc015_c
*/

#include <bits/stdc++.h>
using namespace std;

int get_sum(const vector<vector<int>>& pref, int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> grid(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char c;
            cin >> c;
            grid[i][j] = (c == '1') ? 1 : 0;
        }
    }

    // 1. Prefix Sum for Nodes (Blue Squares)
    vector<vector<int>> pref_nodes(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            pref_nodes[i][j] = grid[i][j] + pref_nodes[i - 1][j] + pref_nodes[i][j - 1] - pref_nodes[i - 1][j - 1];
        }
    }

    // 2. Prefix Sum for Horizontal Edges
    // h_edge[i][j] is 1 if grid[i][j] and grid[i][j+1] are both blue
    vector<vector<int>> pref_h_edges(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < M; ++j) {
            int is_edge = (grid[i][j] == 1 && grid[i][j + 1] == 1) ? 1 : 0;
            pref_h_edges[i][j] = is_edge + pref_h_edges[i - 1][j] + pref_h_edges[i][j - 1] - pref_h_edges[i - 1][j - 1];
        }
        // Fill the last column column M just to keep indexing safe, though it's 0 edges
        pref_h_edges[i][M] = pref_h_edges[i][M-1] + pref_h_edges[i-1][M] - pref_h_edges[i-1][M-1];
    }

    // 3. Prefix Sum for Vertical Edges
    // v_edge[i][j] is 1 if grid[i][j] and grid[i+1][j] are both blue
    vector<vector<int>> pref_v_edges(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int is_edge = (grid[i][j] == 1 && grid[i + 1][j] == 1) ? 1 : 0;
            pref_v_edges[i][j] = is_edge  + pref_v_edges[i - 1][j] + pref_v_edges[i][j - 1] - pref_v_edges[i - 1][j - 1];
        }
    }
    
    // Fill the last row N just to keep indexing safe
    for(int j = 1 ; j <= M; ++j) {
        pref_v_edges[N][j] = pref_v_edges[N][j-1] + pref_v_edges[N-1][j] - pref_v_edges[N-1][j-1];
    }

    for (int k = 0; k < Q; ++k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int nodes = get_sum(pref_nodes, x1, y1, x2, y2);
        int h_edges = get_sum(pref_h_edges, x1, y1, x2, y2 - 1);
        int v_edges = get_sum(pref_v_edges, x1, y1, x2 - 1, y2);

        cout << (nodes - h_edges - v_edges) << "\n";
    }
}