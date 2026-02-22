#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
    
        vector<int> B(2 * N - 1); 
        for (int i = 0; i < B.size(); ++i) {
            B[i] = A[i % N];
        }
    
        vector<int> smaller(B.size(), INT_MAX);
        stack<int> st;
        for (int y = 0; y < B.size(); ++y) {
            while (!st.empty() && B[y] < B[st.top()]) {
                smaller[st.top()] = y;
                st.pop();
            }
            st.push(y);
        }
    
        vector<int> tree(2 * N, INT_MAX);
        auto update = [&](int p, int val) {
            p += N;
            tree[p] = min(tree[p], val);
            for (p /= 2; p > 0; p /= 2) {
                tree[p] = min(tree[2 * p], tree[2 * p + 1]);
            }
        };
        auto query = [&](int l, int r) { 
            int res = INT_MAX;
            for (l += N, r += N; l < r; l /= 2, r /= 2) {
                if (l % 2 == 1) {
                    res = min(res, tree[l++]);
                }
                if (r % 2 == 1) {
                    res = min(res, tree[--r]);
                }
            }
            return res;
        };
    
        vector<int> R(B.size(), INT_MAX);
        for (int i = B.size() - 1; i >= 0; --i) {
            int idx = B[i] - 1;
            
            if (idx > 0) {
                R[i] = query(0, idx); 
            }
            update(idx, smaller[i]);
        }
    
        vector<int> ans;
        deque<int> dq;
        
        for (int i = 0; i < B.size(); ++i) {
            int start = i - N + 1;
            
            while (!dq.empty() && dq.front() < start) {
                dq.pop_front();
            }
            while (!dq.empty() && R[dq.back()] >= R[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
    
            if (i >= N - 1) {
                int mini = R[dq.front()];
                if (mini > i) { 
                    int s = (N - start) % N;
                    ans.push_back(s);
                }
            }
        }
    
        sort(ans.begin(), ans.end());
        
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
        }
        cout << endl;
	}
}