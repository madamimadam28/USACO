/* 
Link for problem: https://atcoder.jp/contests/abc164/tasks/abc164_d
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    map<int, long long> cnt;
    cnt[0] = 1;

    long long ans = 0;
    int mod = 0;
    int pow = 1;

    for (int i = n - 1; i >= 0; --i) {
        int digit = S[i] - '0';
        mod = (mod + digit * pow) % 2019;
        ans += cnt[mod];
        cnt[mod]++;
        pow = (pow * 10) % 2019;
        cout << pow << endl;
    }

    cout << ans << "\n";
}