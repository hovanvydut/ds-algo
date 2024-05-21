#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cost first
#define happy second

ll m, x;
vector<pair<ll, ll>> a;
unordered_map<string, ll> memo;

ll f(ll cur, ll i) {
	if (i >= m+1) return 0;

	string key = to_string(cur) + "_" + to_string(i);
	if (memo.find(key) != memo.end()) {
		return memo[key];
	}

	ll ans = f(cur + x, i + 1);
	if (cur - a[i].cost >= 0) {
		ans = max(ans, a[i].happy + f(cur - a[i].cost + x, i+1));
	}

	memo[key] = ans;
	return ans;
}

void solve () {
	cin >> m >> x;

	a.clear();
	memo.clear();
	a.resize(m+2);
	for (ll i = 1; i <= m; i++) {
		ll c, h;
		cin >> c >> h;
		a[i] = {c, h};
	}

	ll ans = f(0, 1);
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int t;
    cin >> t;

    while (t > 0) {
		solve();	
		t--;
    }
 
	return 0;
}