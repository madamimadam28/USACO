/* 
Link for problem: https://codeforces.com/contest/276/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vector<ll> arr(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<ll> freq(N + 2);
    for (ll i = 0; i < Q; ++i) {
        ll L, R;
        cin >> L >> R;
        freq[L] += 1;
        freq[R + 1] -= 1;
    }

    for (ll i = 1; i <= N; ++i) {
        freq[i] += freq[i - 1];
    }

    sort(arr.begin() + 1, arr.end(), greater<ll>());
    sort(freq.begin() + 1, freq.end(), greater<ll>());

    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
        ans += arr[i] * freq[i];
    }

    cout << ans;
}
