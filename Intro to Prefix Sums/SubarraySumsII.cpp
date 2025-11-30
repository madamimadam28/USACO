/* 
Link for problem: https://cses.fi/problemset/task/1661/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X;
    cin >> N >> X;

    map<long long, int> freq;
    freq[0] = 1;
    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
        ans += freq[sum - X];
        freq[sum]++;
    }

    cout << ans << '\n';
}