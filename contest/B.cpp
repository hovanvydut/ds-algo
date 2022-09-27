/**
 * @author hovanvydut
 * @problem https://bkdnoj.com/contest/icpc_train_5/problem/DEMO5B
 */
 
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll n, m, M;
ll dp[1001][1001];

ll g(ll n, ll m) {
	if (m == 1 || m == n) return 1;
	if (m <= 0) return 0;
	if (n <= 0) return 0;

	return g(n-m, m) + g(n-1, m-1);
}

ll f(int n, ll m) {
	ll s = 0;
	for (ll i = 1; i <= m; i++) {
		s += g(n, i);
		s %= M;
	}
	return s-1;
}

void solve() {
	cin >> n >> m >> M;
	cout << f(n, m);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();	
    return 0;
}