/* 
Link for problem: https://codeforces.com/contest/245/problem/H
*/

#include <bits/stdc++.h>
using namespace std;

static bool isPal[5000][5000];
static int pref[5000][5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        isPal[i][i] = true;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (s[l] == s[r]) {
                if (len == 2 || isPal[l + 1][r - 1]) {
                    isPal[l][r] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pref[i][j] = isPal[i][j];
            if (i > 0) {
                pref[i][j] += pref[i - 1][j];
            }
            if (j > 0) {
                pref[i][j] += pref[i][j - 1];
            }
            if (i > 0 && j > 0) {
                pref[i][j] -= pref[i - 1][j - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        int ans = pref[r][r];
        if (l > 0) {
            ans -= pref[l - 1][r];
            ans -= pref[r][l - 1];
            ans += pref[l - 1][l - 1];
        }

        cout << ans << '\n';
    }

    return 0;
}
