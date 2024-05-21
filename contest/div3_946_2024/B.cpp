#include <bits/stdc++.h>
using namespace std;
 

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> counter(26, 0);
	for (int i = 0; i < n; i++) {
		int k = s[i] - 'a';
		if (counter[k] == 0) {
			counter[k]++;
		}
	}

	unordered_map<char, char> umap;
	int l = 0, r = 25;
	while (l <=r) {
		while (l < r && counter[l] == 0) {
			l++;
		}
		while (l < r && counter[r] == 0) {
			r--;
		}
		char c1 = l + 'a';
		char c2 = r + 'a';
		umap[c1] = c2;
		umap[c2] = c1;
		l++;
		r--;
	}

	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += umap[s[i]];
	}
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