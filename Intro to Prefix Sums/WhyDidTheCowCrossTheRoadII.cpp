/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=715
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("maxcross.in", "r", stdin);
    // freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;
    vector<long long> A(N + 1, 0);
    for (int i = 0; i < B; ++i) {
        int ID;
        cin >> ID;
        A[ID]++;
    }
    vector<long long> pre(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pre[i + 1] = pre[i] + A[i + 1];
    }
    long long ans = LLONG_MAX;
    for (int i = K; i <= N; ++i) {
        ans = min(ans, pre[i] - pre[i - K]);
    }
    cout << ans << '\n';
}
