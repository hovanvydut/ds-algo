#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int x, y;


void solve() {
	cin >> x >> y;

	int screen = y / 2 + (y % 2);
	int ans = screen;

	if (x <= (15 * screen - y * 4)) {
		cout << ans << endl;
		return;
	}

	x -= (15 * screen - y * 4);
	ans += (x / 15) + (x % 15 == 0 ? 0 : 1);

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