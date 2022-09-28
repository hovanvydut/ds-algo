/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/2413
 */
 
/**
Input:
3
2
6
1337

Output:
8
2864
640403945
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_SIZE = 1e6+1;

int n;
vector<int> f;

void input() {
    cin >> n;
    f.resize(n+1, 1e9);
}

void solve() {
    f[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (char c : to_string(i)) {
            f[i] = min(f[i], f[i - (c - '0')] + 1);
        }
    }

    cout << f[n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    solve();

    return 0;
}
