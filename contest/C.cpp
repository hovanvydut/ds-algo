#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<char> vc;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t, n, c, q, l, r, qi;
	char tmp;

	cin >> t;

	for (int ti = 1; ti <= t; ti++) {
		cin >> n >> c >> q;

		vc s;
		s.push_back('x');

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			s.push_back(tmp);
		}



		for (int i = 1; i <= c; i++) {
			cin >> l >> r;
			for (int j = l; j <= r; j++) {
				s.push_back(s[j]);
			}
		}

		for (int i = 1; i <= q; i++) {
			cin >> qi;
			cout << s[qi] << "\n";
		}
	}
	return 0;
}