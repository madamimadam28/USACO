/* 
Link for problem: https://cses.fi/problemset/task/1643/
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int best = 0, ans = 0;
    for (auto x : arr) {
        best = max(x, best + x);
        ans = max(best, ans);
    }

    cout << ans;
}

