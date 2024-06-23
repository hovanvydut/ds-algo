#include <bits/stdc++.h>
using namespace std;
 
#define ll long long


void solve() {
	ll k, c;
    vector<ll> p;
    cin >> k;
    p.resize(k);

    ll n = 1;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        n *= p[i];
    }

    cin >> c;

    ll t = c % n;
    for (ll i = 0; i < n; i++) {
        if (i * i * i == t) {
            cout << i;
            break;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}