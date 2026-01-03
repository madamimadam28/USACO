/* 
Link for problem: https://codeforces.com/contest/195/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Struct {
    int l, r, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<Struct> queries(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].d;
    }

    vector<ll> cnt(M + 2, 0);
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y + 1]--;
    }

    for (int i = 1; i <= M; i++) {
        cnt[i] += cnt[i - 1];
    }

    vector<ll> diff(N + 2, 0);
    for (int i = 1; i <= M; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        ll tot = queries[i].d * cnt[i];
        diff[queries[i].l] += tot;
        diff[queries[i].r + 1] -= tot;
    }

    for (int i = 1; i <= N; i++) {
        diff[i] += diff[i - 1];
        arr[i] += diff[i];
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
