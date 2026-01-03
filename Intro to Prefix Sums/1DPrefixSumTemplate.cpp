#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input array
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    // Build prefix sum array
    vector<long long> prefix(n + 1, 0); // prefix[0] = 0
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Example queries
    int l, r;

    // Sum of elements from index 1 to 3
    l = 1; r = 3;
    cout << "Sum from " << l << " to " << r << ": " << prefix[r + 1] - prefix[l] << endl;

    // Sum of elements from index 0 to 5
    l = 0; r = 5;
    cout << "Sum from " << l << " to " << r << ": " << prefix[r + 1] - prefix[l] << endl;

    return 0;
}
