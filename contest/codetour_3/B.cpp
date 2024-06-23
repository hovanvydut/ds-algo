#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long double res = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {
            res++;
        } else {
            res += sqrt(1.0 + (A[i] - A[i-1]) * (A[i] - A[i-1]));
        }
    }

    cout << fixed << setprecision(6) << res << endl;
    return 0;
}