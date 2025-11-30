/* 
Link for problem: https://judge.yosupo.jp/problem/static_range_sum
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> pre(N + 1, 0);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l] << "\n";
    }
}