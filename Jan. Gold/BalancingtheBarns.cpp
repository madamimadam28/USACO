#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int128 = __int128_t;

ll N, K;
vector<ll> hay;
vector<ll> feed;

int128 cost(ll lim, ll diff) {
    int128 tot = 0;
    for (ll i = 0; i < N; ++i) {
        ll req_hay = hay[i] - lim;
        ll req_feed = lim - diff - feed[i];

        ll ops = 0;
        if (req_hay > ops) {
            ops = req_hay;
        }
        if (req_feed > ops) {
            ops = req_feed;
        }
        
        tot += ops;
    }
    return tot;
}

bool check(ll diff) {
    ll l = -2e18, r = 2e18;
    
    while (r - l > 4) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        
        if (cost(m1, diff) < cost(m2, diff)) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    
    int128 mini = -1;
    for (ll i = l; i <= r; ++i) {
        int128 c = cost(i, diff);
        if (mini == -1 || c < mini) {
            mini = c;
        }
    }

    return mini <= (int128)K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        hay.resize(N);
        feed.resize(N);
        
        for (ll i = 0; i < N; ++i) {
            cin >> hay[i];
        }
        for (ll i = 0; i < N; ++i) {
            cin >> feed[i];
        }
        
        ll l = -2e18, r = 2e9; 
        ll ans = r;
        
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}