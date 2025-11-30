/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=595
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> pre(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pre[i + 1] = (pre[i] + A[i]) % 7;
    }

    vector<int> first(7, -1);
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        int r = pre[i];
        if (first[r] == -1) {
            first[r] = i;
        }
        else {
            ans = max(ans, i - first[r]);
        }
    }

    cout << ans;
}
