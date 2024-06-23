#include <bits/stdc++.h>
using namespace std;
 
#define ll long long


void solve() {
	ll n, k;
	cin >> n >> k;

	ll x = n / k;
	if (n % k != 0) x++;

	ll res = x * (x +1) / 2;

	cout << res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}