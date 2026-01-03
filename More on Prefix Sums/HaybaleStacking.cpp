/* 
Link for problem: https://www.spoj.com/problems/HAYBALE/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> diff(N + 2, 0);

    // Build difference array
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        diff[A]++;
        diff[B + 1]--;
    }

    // Build final array (0-based)
    vector<int> arr(N);
    int curr = 0;
    for (int i = 1; i <= N; i++) {
        curr += diff[i];
        arr[i - 1] = curr;
    }

    sort(arr.begin(), arr.end());

    // Median (middle element)
    cout << arr[N / 2] << "\n";
    return 0;
}
