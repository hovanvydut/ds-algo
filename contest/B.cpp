#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, tmp;
	vi a;
	cin >> t;

	for (int ti = 1; ti <= t; ti++) {
		cin >> n;
		a.assign(n, 0);

		int result = 0;
		for (int i = 0; i < n-1; i++) {
			cin >> a[i];
			if (a[i] > 0) {
				result += a[i];
			}
		}
		cout << result << "\n";
	}
	return 0;
}