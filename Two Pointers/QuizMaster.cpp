/* 
Link for problem: https://codeforces.com/contest/1777/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 1. Fast Input/Output
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 2. Precompute divisors for all numbers up to 100,000
    // We do this ONCE inside main before checking test cases.
    int MAX = 100005;
    vector<vector<int>> divs(MAX);
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divs[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort students by smartness
        sort(a.begin(), a.end());

        vector<int> count(m + 1, 0); // Stores frequency of topics covered
        int have = 0;                // How many topics (1..m) we currently have
        int ans = 1e9;               // Initialize answer with a very large number
        int left = 0;                // Left pointer of the window

        // Sliding Window (Two Pointers)
        for (int right = 0; right < n; right++) {
            // Add the new student (a[right]) to the team
            for (int topic : divs[a[right]]) {
                if (topic > m) continue; // Ignore topics larger than m
                
                if (count[topic] == 0) {
                    have++; // We found a new topic we didn't have before
                }
                count[topic]++;
            }

            // While we have all 'm' topics covered, try to shrink the window from the left
            while (have == m) {
                // Update minimum difference
                int current_diff = a[right] - a[left];
                if (current_diff < ans) {
                    ans = current_diff;
                }

                // Remove the student at 'left' pointer
                for (int topic : divs[a[left]]) {
                    if (topic > m) continue;

                    count[topic]--;
                    if (count[topic] == 0) {
                        have--; // We lost a topic, window is no longer valid
                    }
                }
                left++;
            }
        }

        if (ans == 1e9) {
            cout << -1 << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
}