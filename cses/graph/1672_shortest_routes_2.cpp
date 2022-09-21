/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1672
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, q, a, b, c;
ll dp[501][501];
const ll oo = 1e18;

void input() {
	cin >> n >> m >> q;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			dp[i][j] = oo;
			if (i == j) {
				dp[i][j] = 0;
			}
		}
	}

	for (ll i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dp[a][b] != oo) {
			if (dp[a][b] > c) {
				dp[a][b] = c;
				dp[b][a] = c;
			}
		} else {
			dp[a][b] = c;
			dp[b][a] = c;
		}

	}
}

void solve() {
	input();

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for (ll i = 0; i < q; i++) {
		cin >> a >> b;
		if (dp[a][b] == oo) {
			cout << -1 << endl;
		} else {
			cout << dp[a][b] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();

	return 0;
}