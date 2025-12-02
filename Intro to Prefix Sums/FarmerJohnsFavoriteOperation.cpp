/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=1471
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long N, M;
        cin >> N >> M;
        vector<long long> arr(2 * N, 1e9 + 7);
        for (long long i = 0; i < M; ++i) {
            cin >> arr[i];
            arr[i] %= M;
        }
        sort(arr.begin(), arr.end());
        for (long long i = N; i < 2 * N; ++i) {
            arr[i] = arr[i - N] + M;
        }
        
        long long ans = LLONG_MAX;
        vector<long long> pref(2 * N + 1);
        pref[0] = 0;
        for (long long i = 1; i <= 2 * N; ++i) {
            pref[i] = pref[i - 1] + arr[i - 1];
        }
        
        for (long long i = 0; i < N; ++i) {
            ans = min(ans, pref[N + i] - pref[N + i - N / 2] - pref[N / 2 + i] + pref[i]);
        }
        
        cout << ans << endl;
    }
}