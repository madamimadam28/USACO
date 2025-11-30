/* 
Link for problem: https://cses.fi/problemset/task/1662
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> pre(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pre[i + 1] = (pre[i] + A[i]) % N;
        if (pre[i + 1] < 0) {
            pre[i + 1] += N;
        }
    }

    vector<long long> freq(N, 0);
    for (int i = 0; i <= N; ++i) {
        freq[pre[i]]++;
    }

    long long ans = 0;
    for (int r = 0; r < N; ++r) {
        ans += freq[r] * (freq[r] - 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}
