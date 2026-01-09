/* 
Link for problem: https://codeforces.com/contest/702/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ll> cities(N), towers(M);
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> towers[j];
    }

    int j = 0;
    ll ans = 0;

    for (int i = 0; i < N; i++) {

        // Move tower pointer if next tower is closer
        while (j + 1 < M && abs(towers[j + 1] - cities[i]) <= abs(towers[j] - cities[i])) {
            j++;
        }

        ans = max(ans, abs(towers[j] - cities[i]));
    }

    cout << ans;
}