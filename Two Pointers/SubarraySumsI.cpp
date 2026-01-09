/* 
Link for problem: https://cses.fi/problemset/task/1660/
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int l = 0;
    int sum = 0;
    int ans = 0;

    // r = right pointer of the sliding window
    for (int r = 0; r < N; ++r) {

        // Expand the window by including book r
        sum += A[r];

        while (sum > T) {
            sum -= A[l];  // remove the leftmost
            l++;          // move left pointer right
        }

        // Check if the sum equals T
        if (sum == T) {
            ans++;
        }
    }

    cout << ans;
}