/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=738
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    ll N;
    cin >> N;

    vector<pair<ll, ll>> cows(N);
    for (ll i = 0; i < N; ++i) {
        cin >> cows[i].second >> cows[i].first;
    }

    sort(cows.begin(), cows.end());

    ll ans = 0;
    ll l = 0, r = N - 1;

    // Best case scenario when most paired with least, simulated pairings
    while (l < r) {

        // Answer maximum time for milking
        ll curr = cows[l].first + cows[r].first;
        ans = max(ans, curr);

        // Optimize simulation by subtracting most of pairings bc of repeats
        int sub = min(cows[l].second, cows[r].second);
        cows[l].second -= sub;
        cows[r].second -= sub;

        // Remove cows once finished pairing up
        if (cows[l].second == 0) {
            l++;
        }
        if (cows[r].second == 0) {
            r--;
        }
    }
    cout << ans;
}