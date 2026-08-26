#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    
    while (Q--) {
        ll type;
        cin >> type;
        
        if (type == 1) {
            ll c, t;
            cin >> c >> t;
            ll pos = c;
            ll dest = c;
            
            while (dest < t) {
                if (pos == 0) {
                    pos = (dest + 1) / 2;
                    dest++;
                }
                else {
                    if (2 * pos <= dest) {
                        ll to_zero = pos;
                        if (dest + to_zero <= t) {
                            dest += to_zero;
                            pos = 0;
                        }
                        else {
                            pos -= t - dest;
                            dest = t;
                        }
                    }
                    else {
                        ll in_bound = 2 * pos;
                        
                        if (in_bound > t) {
                            dest = t; 
                        }
                        else {
                            dest = in_bound;
                            pos--; 
                        }
                    }
                }
            }
            cout << pos << endl;
            
        }
        else {
            ll x, t;
            cin >> x >> t;
            
            while (2 * x <= t) {
                ll sum = x + t;
                ll rem = sum % 3;
                
                if (rem == 2) {
                    ll tau = 2 * (sum / 3) + 1;
                    x = sum - tau;
                    break; 
                }
                else {
                    ll tau;
                    if (rem == 0) {
                        tau = 2 * (sum / 3);
                    }
                    else {
                        tau = 2 * (sum / 3) + 1;
                    }
                    
                    x = 0;
                    t = tau - 1;
                }
            }
            cout << x << endl;
        }
    }
}