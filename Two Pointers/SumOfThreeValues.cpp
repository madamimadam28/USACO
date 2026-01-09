/* 
Link for problem: https://cses.fi/problemset/task/1641
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
    
    // Fix the first element
    for (int i = 0; i < N; ++i) {

        int l = i + 1, r = N - 1;
        while (l < r) {

            // Found pair with required sum
            if (A[i].first + A[l].first + A[r].first == X) {
                cout << A[i].second << ' ' << A[l].second << ' ' << A[r].second;
                return 0;
            }

            // Sum too large → decrease right pointer
            else if (A[i].first + A[l].first + A[r].first > X) {
                r--;
            }

            // Sum too small → increase left pointer
            else {
                l++;
            }
        }
    }

    // No valid pair exists
    cout << "IMPOSSIBLE";
}