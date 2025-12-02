/* 
Link for problem: https://codeforces.com/contest/1291/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int s = S.size();
    vector<vector<int>> pre(s + 1, vector<int>(26, 0));
    
    for (int i = 1; i <= s; i++) {
        pre[i] = pre[i - 1];
        pre[i][S[i - 1] - 'a']++;
    }
    
    auto distinct = [&](int l, int r) {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (pre[r][i] - pre[l - 1][i] > 0) {
                cnt++;
            }
        }
        return cnt;
    };

    int N;
    cin >> N;
    while (N--) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << "Yes\n";
            continue;
        }

        int d = distinct(l, r);

        if (d >= 3 || S[l-1] != S[r-1]) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << "\n";
    }
}