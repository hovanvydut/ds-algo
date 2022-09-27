/**
 * @author hovanvydut
 * @problem https://bkdnoj.com/contest/icpc_train_5/problem/DEMO5A
 */
 
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll a, b, c;
void solve() {
	cin >> a >> b >> c;
	if (a % c == b % c) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();	
    return 0;
}