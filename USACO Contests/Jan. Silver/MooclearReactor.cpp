#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll node;
    ll sum;
};

struct State {
    ll sign;
    ll offset;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;
    
        vector<ll> l(N + 1);
        vector<ll> r(N + 1);
        vector<vector<Edge>> adj(N + 1);
    
        for (ll i = 1; i <= N; ++i) {
            cin >> l[i];
        }
        for (ll i = 1; i <= N; ++i) {
            cin >> r[i];
        }
    
        for (ll i = 0; i < M; ++i) {
            ll x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
    
        vector<State> states(N + 1);
        vector<bool> vis(N + 1, false);
        
        ll maxi = 0;
        bool possible = true;
    
        for (ll i = 1; i <= N; ++i) {
            if (vis[i]) continue;
    
            vector<ll> curr;
            vector<ll> bases;
            bool fixed = false;
            bool check = false;
    
            vector<ll> q;
            q.push_back(i);
            vis[i] = true;
            
            states[i] = {1, 0}; 
            curr.push_back(i);
    
            ll head = 0;
            while(head < q.size()){
                ll u = q[head++];
                
                for (const auto& edge : adj[u]) {
                    ll v = edge.node;
                    ll z = edge.sum;
                    
                    if (!vis[v]) {
                        vis[v] = true;
                        states[v] = {-states[u].sign, z - states[u].offset};
                        curr.push_back(v);
                        q.push_back(v);
                    }
                    else {
                        ll sign = states[u].sign + states[v].sign;
                        ll right = z - states[u].offset - states[v].offset;
    
                        if (sign == 0) {
                            if (right != 0) {
                                check = true;
                            }
                        }
                        else {
                            if (abs(right) % 2 != 0) {
                                check = true;
                            }
                            else {
                                ll energy = right / sign;
                                if (fixed && energy != bases[0]) {
                                    check = true;
                                }
                                
                                if (!fixed) {
                                    fixed = true;
                                    bases.push_back(energy);
                                }
                            }
                        }
                    }
                }
            }
    
            if (check) {
                possible = false;
                break;
            }
    
            if (fixed) {
                ll energy = bases[0];
                ll cnt = 0;
                for (ll node : curr) {
                    ll exact_energy = states[node].sign * energy + states[node].offset;
                    if (exact_energy >= l[node] && exact_energy <= r[node]) {
                        cnt++;
                    }
                }
                maxi += cnt;
            }
            else {
                vector<pair<ll, ll>> events;
                
                for (ll node : curr) {
                    ll start, end;
                    ll offset = states[node].offset;
                    
                    if (states[node].sign == 1) {
                        start = l[node] - offset;
                        end = r[node] - offset;
                    }
                    else {
                        start = offset - r[node];
                        end = offset - l[node];
                    }
                    
                    if (start <= end) {
                        events.push_back({start, 1});
                        events.push_back({end + 1, -1});
                    }
                }
                
                sort(events.begin(), events.end());
                
                ll overlap = 0;
                int curr = 0;
                
                for (ll j = 0; j < events.size(); ++j) {
                    curr += events[j].second;
                    if (j + 1 == events.size() || events[j + 1].first != events[j].first) {
                        if (curr > overlap) {
                            overlap = curr;
                        }
                    }
                }
                maxi += overlap;
            }
        }
    
        if (!possible) {
            cout << -1 << endl;
        }
        else {
            cout << maxi << endl;
        }
    }
}