/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1637
 */
 
/**
Input:
27

Output:
5
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_SIZE = 1e6+1;

int n;
int f[MAX_SIZE];

void input() {
    cin >> n;
}

void solve() {
    if (n <= 9) {
        cout << 1;
        return;
    }

    for (int i = 0; i <= n; i++) {
        if (i <= 9) {
            f[i] = 1;
        } else {
            f[i] = INF;
            int t = i;
            while (t) {
                int digit = t % 10;
                t = t / 10;
                f[i] = min(f[i], f[i-digit]);
            }
            f[i] = f[i] + 1;
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

/** RECURSION + MEMORIZE

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_SIZE = 1e6+1;

int n;
int cached[MAX_SIZE];
bool ready[MAX_SIZE];

void input() {
    cin >> n;
}

int solve(int n) {
    if (ready[n]) return cached[n];
    if (n <= 9) return 1;

    int t = n;
    int f = INF;
    while (t) {
        int digit = t % 10;
        t = t / 10;
        if (digit == 0) continue;
        f = min(f, solve(n-digit));
    }
    f = f + 1;

    ready[n] = true;
    cached[n] = f;
    return f;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    int result = solve(n);
    cout << result;

    return 0;
}
 */
