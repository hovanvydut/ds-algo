#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

ll N;
vector<ll> A;
void solve() {
	cin >> N;
    A.resize(N, 0);

    ll s = 1;
    int pivot = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 1 && pivot == -1) {
            pivot = i;
        }
        if (pivot != -1) {
            if (s >= A[i]) {
                s += A[i];
            } else {
                pivot = -1;
                s = 1;
            }
        }
    }

    if (pivot == -1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = pivot - 1; i >= 0; i--) {
        if (s >= A[i]) {
            s += A[i];
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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