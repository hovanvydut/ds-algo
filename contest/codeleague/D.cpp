#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

ll n, k, d;
vector<ll> t;
vector<ll> a;
vector<ll> b;
unordered_map<string, ll> memo;

ll dfs(ll i, ll prevTaskA, ll prevTaskB, ll delayA, ll delayB) {
	if (i >= t.size()) {
		return 0;
	}

	string key = to_string(i) + "_" + to_string(prevTaskA) + "_" + to_string(prevTaskB) + "_" + to_string(delayA) + "_" + to_string(delayB);
	if (memo.count(key)) {
		return memo[key];
	}

	if (delayA >= d) {
		ll res1 = (prevTaskA == t[i] ? b[t[i]] : a[t[i]]) + dfs(i + 1, t[i], prevTaskB, 0, delayB + 1);
		return res1;
	} else if (delayB >= d) {
		ll res2 = (prevTaskB == t[i] ? b[t[i]] : a[t[i]]) + dfs(i + 1, prevTaskA, t[i], delayA + 1, 0);
		return res2;
	}

	ll res1 = (prevTaskA == t[i] ? b[t[i]] : a[t[i]]) + dfs(i + 1, t[i], prevTaskB, 0, delayB + 1);
	ll res2 = (prevTaskB == t[i] ? b[t[i]] : a[t[i]]) + dfs(i + 1, prevTaskA, t[i], delayA + 1, 0);

	ll res = min(res1, res2);
	memo[key] = res;
	return res;
}

void solve() {
	memo.clear();

	cin >> n >> k >> d;
	t.resize(n + 1, 0); a.resize(k + 1, 0); b.resize(k + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}

	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		cin >> b[i];
	}

	ll ans = dfs(1, -1, -1, 0, 0);
	cout << ans << endl;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t > 0) {
		solve();	
		t--;
    }

    return 0;
}
