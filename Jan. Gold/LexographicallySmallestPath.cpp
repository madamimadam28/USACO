#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    char c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
    
        vector<vector<Edge>> adj(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<int> dist(N + 1, -1);
        vector<bool> inf(N + 1, false);
        
        vector<int> curr = {1};
        dist[1] = 0;
    
        for (int i = 0; i < N; ++i) {
            if (curr.empty()) {
                break;
            }
    
            char min_c = '{';
            for (int u : curr) {
                for (auto edge : adj[u]) {
                    if (edge.c < min_c) {
                        min_c = edge.c;
                    }
                }
            }
    
            if (min_c == '{') {
                break;
            }
    
            vector<int> next;
            vector<int> reached(N + 1, 0);
    
            for (int u : curr) {
                for (auto edge : adj[u]) {
                    if (edge.c == min_c) {
                        if (dist[edge.to] == -1 || dist[edge.to] == i + 1) {
                            if (dist[edge.to] == -1) {
                                dist[edge.to] = i + 1;
                                next.push_back(edge.to);
                            }
                            reached[edge.to]++;
                            if (inf[u]) {
                                inf[edge.to] = true;
                            }
                        }
                    }
                }
            }
    
            for (int v : next) {
                if (reached[v] > 1) {
                    inf[v] = true;
                }
            }
    
            sort(next.begin(), next.end());
            next.erase(unique(next.begin(), next.end()), next.end());
            curr = next;
        }
    
        for (int i = 1; i <= N; ++i) {
            if (inf[i] || dist[i] == -1) {
                cout << -1;
            }
            else {
                cout << dist[i] << (i == N ? "" : " ");
            }
        }
        cout << "\n";
    }
}