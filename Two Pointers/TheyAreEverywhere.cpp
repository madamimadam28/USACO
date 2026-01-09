/* 
Link for problem: https://codeforces.com/contest/701/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    // Step 1: Find all unique Pokemon types in the entire house
    set<char> types;
    for (char c : s) {
        types.insert(c);
    }
    int cnt = types.size();

    // Step 2: Sliding Window technique
    int left = 0;
    int ans = n + 1; // Initialize with a value larger than max possible
    int curr = 0;
    
    // Using a simple array for frequency map (ASCII size is 128, 256 covers everything)
    // This is faster than std::map
    vector<int> freq(256, 0); 

    for (int right = 0; right < n; ++right) {
        // Add character at 'right' to the window
        char current_char = s[right];
        if (freq[current_char] == 0) {
            curr++;
        }
        freq[current_char]++;

        // While the window is valid (contains all unique types)
        while (curr == cnt) {
            // Update the minimum length found so far
            ans = min(ans, right - left + 1);

            // Try to shrink the window from the left
            char char_to_remove = s[left];
            freq[char_to_remove]--;
            
            // If the count drops to 0, we lost a unique type
            if (freq[char_to_remove] == 0) {
                curr--;
            }
            left++;
        }
    }

    cout << ans << endl;

    return 0;
}