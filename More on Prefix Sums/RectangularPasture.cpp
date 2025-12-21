/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=1063
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> prefix;

bool cmp(pair<int, int> p, pair<int, int> q) {
    return p.second < q.second; 
}

int sum(int x1, int y1, int x2, int y2) {
    return prefix[x2 + 1][y2 + 1] 
         - prefix[x1][y2 + 1] 
         - prefix[x2 + 1][y1] 
         + prefix[x1][y1];
}

int main() {
    cin >> n;
    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    sort(coords.begin(), coords.end());
    for (int i = 0; i < n; i++) {
        coords[i].first = i + 1;
    }

    sort(coords.begin(), coords.end(), cmp);
    for (int i = 0; i < n; i++) {
        coords[i].second = i + 1;
    }

    prefix.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        int x = coords[i].first;
        int y = coords[i].second;
        prefix[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x1 = min(coords[i].first, coords[j].first) - 1;
            int x2 = max(coords[i].first, coords[j].first) - 1;
            ans += 1LL * sum(0, i, x1, j) * sum(x2, i, n - 1, j);
        }
    }

    cout << ans + 1;
    return 0;
}