/* 
Link for problem: https://codeforces.com/contest/1398/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<long long, long long> freq;

        long long prefix = 0;
        long long ans = 0;
        freq[0] = 1;

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            prefix += (digit - 1);
            ans += freq[prefix];
            freq[prefix]++;
        }

        cout << ans << "\n";
    }
    return 0;
}