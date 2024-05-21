#include <bits/stdc++.h>
using namespace std;
 
#define ll long long


void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll ans = 0;

	map<string, int> umap1;
	map<string, int> umap2;
	map<string, int> umap3;
	map<string, int> umap;

	for (int i = 0; i < n-2; i++) {
		int x = a[i], y = a[i+1], z = a[i+2];
		
		string k1 = to_string(x) + "_" + to_string(y) + "_*";	
		string k2 = to_string(x) + "_*_" + to_string(z);
		string k3 = "*_" + to_string(y) + "_" + to_string(z);
		string k = to_string(x) + "_" + to_string(y) + "_" + to_string(z);

		if (!umap.count(k)) {
			umap[k] = 0;
		}

		if (umap1.count(k1)) {
			ans += umap1[k1] - umap[k];
		}

		if (umap2.count(k2)) {
			ans += umap2[k2] - umap[k];
		}

		if (umap3.count(k3)) {
			ans += umap3[k3] - umap[k];
		}

		umap1[k1]++;
		umap2[k2]++;
		umap3[k3]++;
		umap[k]++;
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