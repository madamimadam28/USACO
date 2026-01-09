/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=643
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int min_moves = 0;

    // Special Edge Case: 
    // If N-1 cows are already consecutive and the single outlier is far away (gap > 2),
    // we are forced to take 2 moves.
    // Example: 1, 2, 3, ..., 100. We can't put 100 next to 3 immediately.
    // We must move 1 to 4 (temp setup), then 100 to 5.
    
    // Case 1: First N-1 cows are consecutive, last one is outlier
    bool case1 = (a[n-2] - a[0] == n - 2) && (a[n-1] - a[n-2] > 2);
    // Case 2: Last N-1 cows are consecutive, first one is outlier
    bool case2 = (a[n-1] - a[1] == n - 2) && (a[1] - a[0] > 2);

    if (case1 || case2) {
        min_moves = 2;
    }
    else {
        // General Case: Sliding Window
        // Find a window of size N that contains the maximum number of cows.
        // Moves needed = N - (max cows already in window)
        int max_cows_in_window = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            // Expand window end (j) while the range fits within size N
            // We want a[j] - a[i] <= N - 1
            while (j < n && a[j] - a[i] < n) {
                j++;
            }
            max_cows_in_window = max(max_cows_in_window, j - i);
        }
        min_moves = n - max_cows_in_window;
    }

    // --- CALCULATION FOR MAXIMUM MOVES ---
    // Max moves = (Total Empty Slots) - (Empty Slots we are forced to lose)
    
    int gap_start = a[1] - a[0] - 1;       // Gaps between index 0 and 1
    int gap_end = a[n-1] - a[n-2] - 1;     // Gaps between index N-2 and N-1
    int total_empty = (a[n-1] - a[0] + 1) - n; // Total missing integers in range
    
    int max_moves = total_empty - min(gap_start, gap_end);

    cout << min_moves << "\n";
    cout << max_moves << "\n";
}