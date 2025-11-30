/* 
Link for problem: https://usaco.org/index.php?page=viewproblem2&cpid=691
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);

    int N;
    cin >> N;
    vector<char> moves(N);
    for (int i = 0; i < N; ++i) {
        cin >> moves[i];
    }
    vector<int> preH(N + 1, 0);
    vector<int> preP(N + 1, 0);
    vector<int> preS(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        preH[i + 1] = preH[i] + (moves[i] == 'H' ? 1 : 0);
        preP[i + 1] = preP[i] + (moves[i] == 'P' ? 1 : 0);
        preS[i + 1] = preS[i] + (moves[i] == 'S' ? 1 : 0);
    }
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        int leftH = preH[i];
        int leftP = preP[i];
        int leftS = preS[i];
        int rightH = preH[N] - preH[i];
        int rightP = preP[N] - preP[i];
        int rightS = preS[N] - preS[i];

        ans = max(ans, leftH + rightH);
        ans = max(ans, leftH + rightP);
        ans = max(ans, leftH + rightS);
        ans = max(ans, leftP + rightH);
        ans = max(ans, leftP + rightP);
        ans = max(ans, leftP + rightS);
        ans = max(ans, leftS + rightH);
        ans = max(ans, leftS + rightP);
        ans = max(ans, leftS + rightS);
    }
    cout << ans;
}
