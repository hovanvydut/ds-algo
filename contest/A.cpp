#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, x, p;
	vi h;
	string result;

	cin >> t;

	for (int ti = 1; ti <= t; ti++) {
		result = "YES";
		cin >> n >> x;

		h.assign(2*n, 0);
		for (int i = 0; i < 2*n; i++) {
			cin >> h[i];
		}

		sort(h.begin(), h.end());

		for (int i = 0; i < n; i++) {
			if (h[i+n] - h[i] < x) {
				result = "NO";
				break;
			}
		}
		cout << result << "\n";
	}

	return 0;
}