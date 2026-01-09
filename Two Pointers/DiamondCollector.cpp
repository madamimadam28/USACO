/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=643
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 1. Sort
    sort(A.begin(), A.end());

    // 2. Sliding Window to find max capacity starting at each i
    vector<int> can_take(N);
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && A[r] - A[l] <= K) {
            r++;
        }
        can_take[l] = r - l;
    }

    // 3. Suffix Max Array
    // max_after[i] holds the max value found in can_take from i to end
    vector<int> max_after(N + 1, 0); 
    for (int i = N - 1; i >= 0; i--) {
        max_after[i] = max(can_take[i], max_after[i + 1]);
    }

    // 4. Combine two cases
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int val = can_take[i];
        if (i + can_take[i] < N) {
            val += max_after[i + can_take[i]];
        }
        ans = max(ans, val);
    }

    cout << ans << endl;
}