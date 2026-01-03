/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=919
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    ll N, K;
    cin >> N >> K;

    // Difference array
    vector<vector<ll>> diff(1005, vector<ll>(1005, 0));

    for (ll i = 0; i < N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //Shift all coordinates by +1 so we don't have to worry about index 0
        x1++; y1++; x2++; y2++;

        diff[x1][y1]++;
        diff[x1][y2]--;
        diff[x2][y1]--;
        diff[x2][y2]++;
    }

    // Build final grid using prefix sums
    vector<vector<ll>> grid(1005, vector<ll>(1005, 0));

    // Calculate prefix sums
    // Because we shifted coordinates, we can safely loop 1..1000
    // and access [i-1][j-1] without going out of bounds.
    for (ll i = 1; i <= 1000; i++) {
        for (ll j = 1; j <= 1000; j++) {
            grid[i][j] = diff[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }

    ll ans = 0;
    // Iterate through the valid area to count K
    for (ll i = 1; i <= 1000; i++) {
        for (ll j = 1; j <= 1000; j++) {
            if (grid[i][j] == K) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}