#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vi a(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	bool ok = true;
	for (int i = 2; i <= n; i++) {
		if (a[i] % a[1] != 0) {
			ok = false;
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) solve();

	return 0;
}