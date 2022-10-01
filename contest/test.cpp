/**
 * @author hovanvydut
 * Status: Done
 * Submit #2
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t, n;

ll calc(ll n) {
	ll result = 0;
	for (ll x = 2; x <= n; ++x) {
        ll c = 0;
        while (n % x == 0) {
            n /= x;
           	c++;
        };
        result += c;
    }
    return result;
}

void solve() {
	cin >> n;
	if (n == 1) {
		cout << 1;
		return;
	};
	ll f1 = 1;
	ll f2;
	for (int i = 2; i <= n; i++) {
		ll tmp = calc(i);
		// cout << f1 << endl;
		f2 = f1 + tmp;
		f1 = f2;
	}
	cout << f1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
