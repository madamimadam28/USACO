/* 
Link for problem: https://codeforces.com/gym/104114/problem/N
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 1; i < N; i++) {
        S[i] = max(S[i], S[i - 1] - M);
    }

    for (int i = N - 2; i >= 0; i--) {
        S[i] = max(S[i], S[i + 1] - M);
    }

    for (int i = 0; i < N; i++) {
        cout << S[i] << ' ';
    }
}

