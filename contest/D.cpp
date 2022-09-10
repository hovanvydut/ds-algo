#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve () {
	ll n; 
	cin >> n;

	int a1 = 2, a2 = 1, a3 = 1, a4 = 0;
	if (n == 1) {
		cout << 2 << endl;
		return;
	}
	if (n == 2) {
		cout << 1 << endl;
		return;
	}
	if (n == 3) {
		cout << 1 << endl;
		return;
	}
	for (int i = 4; i <= n; i++) {
		int r1 = a1 + 1;
		int r2 = a2 + 1;
		int r3 = a3 + 2;
		if (r1 <= r2 && r1 <= r3) {
			a4 = r1;
		} else if (r2 <= r1 && r2 <= r3) {
			a4 = r2;
		} else {
			a4 = r3;
		}
		a1 = a2;
		a2 = a3;
		a3 = a4;
	}
	cout << a4 << endl;
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) solve();
 
	return 0;
}