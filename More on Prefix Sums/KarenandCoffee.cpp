/* 
Link for problem: https://codeforces.com/contest/816/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    const int MAX_TEMP = 200000;

    // Difference array for recipe coverage
    vector<int> diff(MAX_TEMP + 2, 0);

    // Read recipes
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    // cnt[t] = how many recipes include temperature t
    vector<int> cnt(MAX_TEMP + 1, 0);
    int curr = 0;
    for (int t = 1; t <= MAX_TEMP; t++) {
        curr += diff[t];
        cnt[t] = curr;
    }

    // check[t] = 1 if temperature t is admissible
    vector<int> check(MAX_TEMP + 1, 0);
    for (int t = 1; t <= MAX_TEMP; t++) {
        if (cnt[t] >= k) {
            check[t] = 1;
        }
    }

    // Prefix sum over admissible temperatures
    vector<int> pref(MAX_TEMP + 1, 0);
    for (int t = 1; t <= MAX_TEMP; t++) {
        pref[t] = pref[t - 1] + check[t];
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }
}
