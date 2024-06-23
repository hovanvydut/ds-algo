#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int n, q;
vector<int> h;

void solve() {
	cin >> n >> q;
	h.resize(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int x;
	for (int i = 0; i < q; i++) {
		cin >> x;

		int lo = 0, hi = h.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;

			if (h[mid] <= x) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		h.insert(h.begin() + lo, x);
		cout << lo + 1<< endl;
	}


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}