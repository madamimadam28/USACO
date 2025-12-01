/* 
Link for problem: https://atcoder.jp/contests/abc125/tasks/abc125_c
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> preGCD(N + 1, 0);
    vector<int> sufGCD(N + 1, 0);
    for (int i = 0; i < N; i++) {
        preGCD[i + 1] = gcd(preGCD[i], A[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        sufGCD[i] = gcd(sufGCD[i + 1], A[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, gcd(preGCD[i], sufGCD[i + 1]));
    }
    cout << ans << "\n";
}