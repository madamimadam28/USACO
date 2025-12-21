/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=416
*/

#include <bits/stdc++.h>
using namespace std;

long long grid[805][805];
long long pref[805][805];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    int SIZE = 2 * N + 2;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int g;
            cin >> g;
            int u = r + c;
            int v = r - c + N;
            grid[u][v] += g;
        }
    }

    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    long long ans = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int u = r + c;
            int v = r - c + N;

            int u1 = max(1, u - K);
            int u2 = min(SIZE - 1, u + K);
            int v1 = max(1, v - K);
            int v2 = min(SIZE - 1, v + K);

            long long sum = pref[u2][v2] - pref[u1 - 1][v2] - pref[u2][v1 - 1] + pref[u1 - 1][v1 - 1];

            ans = max(ans, sum);
        }
    }

    cout << ans << "\n";
    return 0;
}
