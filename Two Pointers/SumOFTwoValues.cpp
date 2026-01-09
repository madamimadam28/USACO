/* 
Link for problem: https://cses.fi/problemset/task/1640/
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    // Sort by value to enable two-pointer search
    sort(A.begin(), A.end());
    
    int l = 0, r = N - 1;
    while (l < r) {

        // Found pair with required sum
        if (A[l].first + A[r].first == X) {
            cout << A[l].second << ' ' << A[r].second;
            return 0;
        }

        // Sum too large → decrease right pointer
        else if (A[l].first + A[r].first > X) {
            r--;
        }

        // Sum too small → increase left pointer
        else {
            l++;
        }
    }

    // No valid pair exists
    cout << "IMPOSSIBLE";
}