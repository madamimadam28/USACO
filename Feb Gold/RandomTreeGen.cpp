#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAXN = 200005;

ll inv[MAXN], invFact[MAXN];

int N;
vector<vector<int>> adj;
vector<int> sz;
ll tot;

void precompute() {
    invFact[0] = 1;
    inv[1] = 1;
    for (int i = 1; i < MAXN; i++) {
        if (i > 1) {
            inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        }
        invFact[i] = invFact[i - 1] * inv[i] % MOD;
    }
}

ll power (ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs2(int u, int p, ll curr) {
    tot = (tot + curr) % MOD;
    for (int v : adj[u]) {
        if (v != p) {
            ll nxt = curr * sz[v] % MOD * inv[N - sz[v]] % MOD;
            dfs2(v, u, nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
    
        adj.assign(N + 1, vector<int>());
        sz.assign(N + 1, 0);
        
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        dfs1(1, 0);
    
        ll prod = 1;
        for (int i = 1; i <= N; i++) {
            prod = prod * sz[i] % MOD;
        }
        ll inv = power(prod, MOD - 2);
    
        tot = 0;
        dfs2(1, 0, inv); 
    
        cout << tot * invFact[N - 1] % MOD << endl;
    }
}