#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M, K, L;
        cin >> N >> M >> K >> L;
    
        vector<int> S(K);
        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }
    
        vector<int> D(L);
        for (int i = 0; i < L; i++) {
            cin >> D[i];
        }
    
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> dist(N + 1, -1);
        queue<int> q;
        
        q.push(1);
        dist[1] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    
        bool check_chain = true;
        for (int s : S) {
            if (dist[s] == -1) {
                check_chain = false;
            }
        }

        if (check_chain) {
            sort(S.begin(), S.end(), [&](int a, int b) {
                return dist[a] < dist[b];
            });
            for (int i = 1; i < K; i++) {
                if (dist[S[i]] == dist[S[i-1]]) {
                    check_chain = false;
                    break;
                }
            }
        }

        if (!check_chain) {
            cout << string(N - 1, '0') << endl;
            continue;
        }

        vector<bool> check_S(N + 1, false);
        vector<int> req(N + 1, 0);
        for (int i = 0; i < K; i++) {
            check_S[S[i]] = true;
            req[S[i]] = i + 1;
        }

        vector<vector<int>> topo(N + 1);
        for (int i = 1; i <= N; i++) {
            if (dist[i] != -1) {
                topo[dist[i]].push_back(i);
            }
        }

        vector<int> pref(N + 1, -1);
        pref[1] = 0;

        for (int i = 0; i < N; i++) {
            for (int u : topo[i]) {
                if (pref[u] == -1) {
                    continue; 
                }
                for (int v : adj[u]) {
                    if (dist[v] == dist[u] + 1) { 
                        int nxt = pref[u];
                        if (check_S[v]) {
                            if (pref[u] >= req[v] - 1) {
                                nxt = req[v];
                            }
                            else {
                                nxt = -1; 
                            }
                        }
                        pref[v] = max(pref[v], nxt);
                    }
                }
            }
        }

        vector<int> req_pref(N + 1, 1e9);
        for (int d : D) {
            if (dist[d] != -1) {
                req_pref[d] = K; 
            }
        }

        for (int i = N; i >= 0; i--) {
            for (int v : topo[i]) {
                if (req_pref[v] == 1e9) {
                    continue;
                }
                
                int push = req_pref[v];
                if (check_S[v]) {
                    if (req_pref[v] <= req[v]) {
                        push = req[v] - 1;
                    }
                    else {
                        continue;
                    }
                }
                
                for (int u : adj[v]) {
                    if (dist[u] == dist[v] - 1) { 
                        req_pref[u] = min(req_pref[u], push);
                    }
                }
            }
        }
    
        string ans = "";
        for (int i = 2; i <= N; i++) {
            if (pref[i] != -1 && req_pref[i] != 1e9 && pref[i] >= req_pref[i]) {
                ans += "1";
            }
            else {
                ans += "0";
            }
        }
        cout << ans << endl;
    }
}