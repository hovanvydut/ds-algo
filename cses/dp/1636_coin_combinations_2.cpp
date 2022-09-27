/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1636
 */
 
/**
Input:
3 9
2 3 5
 
Output:
8
 */
 
#include <bits/stdc++.h>
using namespace std;

int n, x, t;
vector<int> c;

const int MOD = (int) 1e9 + 7;
 
void solve() {
    cin >> n >> x;
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 0; i < n; i++) {
        cin >> t;
        c.push_back(t);
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j - c[i-1];
            if (left >= 0) {
                dp[i][j] += dp[i][left];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n][x];
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}