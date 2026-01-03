/* 
Link for problem: https://codeforces.com/contest/2030/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;

        // Read permutation p
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
        }

        string s;
        cin >> s;

        // --- Step 1: Identify Mandatory Edges using Difference Array ---
        // There are n-1 edges. Edge k connects index k and k+1.
        // diff[k] will track coverage for edge k.
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            // Element at i needs to go to p[i].
            // It must cover edges in range [min(i, p[i]), max(i, p[i]) - 1]
            int start = min(i, p[i]);
            int end = max(i, p[i]);
            
            // Standard difference array update: [L, R) -> add to L, sub from R
            if (start < end) {
                diff[start]++;
                diff[end]--;
            }
        }

        // Compute prefix sums to determine which edges are required
        // req[k] is true if edge k (between k and k+1) must be connected
        vector<bool> req(n - 1, false);
        int covered = 0;
        for (int k = 0; k < n - 1; ++k) {
            covered += diff[k];
            if (covered > 0) {
                req[k] = true;
            }
        }

        // --- Step 2: Initialize Connectivity and Bad Edges Count ---
        
        // Helper lambda to check if edge k is currently connected based on string s
        // Edge k connects k and k+1.
        // It is connected if s[k] == 'R' (flow to right) OR s[k+1] == 'L' (flow to left)
        auto conn = [&](int k) {
            return (s[k] == 'R' || s[k + 1] == 'L');
        };

        int bad = 0;
        for (int k = 0; k < n - 1; ++k) {
            if (req[k] && !conn(k)) {
                bad++;
            }
        }

        // --- Step 3: Process Queries ---
        while (q--) {
            int pos;
            cin >> pos;
            pos--;

            // Updating s[pos] affects edges: 
            // 1. Edge (pos-1) -> connects (pos-1) and pos
            // 2. Edge (pos)   -> connects pos and (pos+1)
            
            // We only care about edges within bounds [0, n-2]
            // Note: Problem guarantees 2 <= input_pos <= n-1, so 1 <= pos <= n-2
            // Therefore, pos-1 is >= 0 and pos is <= n-2. Both edges exist.

            int edges[] = {pos - 1, pos};

            // Remove old status of these edges from bad
            for (int k : edges) {
                if (req[k] && !conn(k)) {
                    bad--;
                }
            }

            s[pos] = (s[pos] == 'L') ? 'R' : 'L';

            for (int k : edges) {
                if (req[k] && !conn(k)) {
                    bad++;
                }
            }

            if (bad == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}