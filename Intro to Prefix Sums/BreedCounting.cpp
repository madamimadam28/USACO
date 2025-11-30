/* 
Link for problem: www.usaco.org/index.php?page=viewproblem2&cpid=572
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("bcount.in", "r", stdin);
    // freopen("bcount.out", "w", stdout);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> H(N, 0);
    vector<int> G(N, 0);
    vector<int> J(N, 0);

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 1) H[i] = 1;
        if (x == 2) G[i] = 1;
        if (x == 3) J[i] = 1;
    }

    vector<int> preH(N + 1, 0);
    vector<int> preG(N + 1, 0);
    vector<int> preJ(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        preH[i + 1] = preH[i] + H[i];
        preG[i + 1] = preG[i] + G[i];
        preJ[i + 1] = preJ[i] + J[i];
    }

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << preH[b] - preH[a - 1] << ' ';
        cout << preG[b] - preG[a - 1] << ' ';
        cout << preJ[b] - preJ[a - 1] << '\n';
    }
}