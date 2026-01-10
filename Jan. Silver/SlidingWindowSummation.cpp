#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        string R;
        cin >> R;
        
        vector<ll> r;
        for (ll i = 0; i < R.size(); ++i) {
            r.push_back(R[i] - '0');
        }

        ll min_diff = LLONG_MAX;
        
        ll mini = 0;
        ll minpar = 0;
        
        ll maxi = 0;
        ll maxpar = 0;
    
        for (ll k = 0; k < K; ++k) {
            ll cnt0 = 0;
            ll len = 0;
            
            ll idx = k;
            ll val = 0;
            
            while (idx < N) {
                len++;
                if (val == 1) {
                    cnt0++;
                }
                
                if (idx < N - K) {
                    ll trans = r[idx] ^ r[idx + 1];
                    val ^= trans;
                }
                
                idx += K;
            }
            
            ll cnt1 = len - cnt0;
            
            if (cnt0 <= cnt1) {
                mini += cnt0;
                minpar ^= 0;
            }
            else {
                mini += cnt1;
                minpar ^= 1;
            }
            
            if (cnt0 >= cnt1) {
                maxi += cnt0;
                maxpar ^= 0;
            }
            else {
                maxi += cnt1;
                maxpar ^= 1;
            }
            
            min_diff = min(min_diff, abs(cnt0 - cnt1));
        }
    
        ll target = r[0];
    
        if (minpar != target) {
            mini += min_diff;
        }
    
        if (maxpar != target) {
            maxi -= min_diff;
        }
    
        cout << mini << " " << maxi << endl;
    }
}