/* 
Link for problem: https://codeforces.com/contest/1826/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> B(N);
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        // b[i] + i + b[mid] + b[j] - j
        vector<ll> left(N, LLONG_MIN);
        ll bestleft = LLONG_MIN;
        for (int i = 0; i < N; i++) {
            left[i] = bestleft;
            bestleft = max(bestleft, B[i] + i);
        }

        vector<ll> right(N, LLONG_MIN);
        ll bestright = LLONG_MIN;
        for (int i = N - 1; i >= 0; i--) {
            right[i] = bestright;
            bestright = max(bestright, B[i] - i);
        }

        ll ans = LLONG_MIN;
        for (int i = 0; i < N; i++) {
            ans = max(ans, left[i] + B[i] + right[i]);
        }
        cout << ans << "\n";
    }
}