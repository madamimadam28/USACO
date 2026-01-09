/* 
Link for problem: https://codeforces.com/contest/279/problem/B?locale=en
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

    // l = left pointer of the sliding window
    // sum = total time of books in current window [l, r]
    // ans = maximum number of books we can read
    int l = 0;
    int sum = 0;
    int ans = 0;

    // r = right pointer of the sliding window
    for (int r = 0; r < N; ++r) {

        // Expand the window by including book r
        sum += A[r];

        /*
        If the total time exceeds T, the window is invalid.
        Since all A[i] > 0, increasing r only increases sum.
        So the ONLY way to fix this is to move l forward
        (shrink from the left).
        */
        while (sum > T) {
            sum -= A[l];  // remove the leftmost book
            l++;          // move left pointer right
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
}