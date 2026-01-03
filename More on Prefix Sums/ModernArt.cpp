/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=744
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int maxLabel = n * n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    const int INF = 1e9;
    vector<int> rmin(maxLabel+1, INF), rmax(maxLabel+1, -1);
    vector<int> cmin(maxLabel+1, INF), cmax(maxLabel+1, -1);
    vector<char> appears(maxLabel + 1, 0);

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int v = grid[r][c];
            appears[v] = 1;
            rmin[v] = min(rmin[v], r);
            rmax[v] = max(rmax[v], r);
            cmin[v] = min(cmin[v], c);
            cmax[v] = max(cmax[v], c);
        }
    }

    vector<int> indeg(maxLabel + 1, 0);
    vector<int> lastSeen(maxLabel + 1, -1);

    for (int v = 1; v <= maxLabel; ++v) {
        if (!appears[v]) {
            continue;
        }
        for (int r = rmin[v]; r <= rmax[v]; ++r) {
            for (int c = cmin[v]; c <= cmax[v]; ++c) {
                int u = grid[r][c];
                if (u == v) {
                    continue;
                }
                if (lastSeen[u] != v) {
                    lastSeen[u] = v;
                    indeg[u]++;
                }
            }
        }
    }

    long long ans = 0;
    for (int v = 1; v <= maxLabel; ++v) {
        if (indeg[v] == 0) {
            ans++;
        }
    }
    
    int appearCount = 0;
    for (int v = 1; v <= maxLabel; ++v) {
        if (appears[v]) {
            ++appearCount;
        }
    }
    
    if (appearCount == 1) {
        ans = max(0LL, ans - 1);
    }

    cout << ans;
}