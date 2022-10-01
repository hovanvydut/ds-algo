/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1158
 */
 
/**
Input:
4 10
4 8 5 3
5 12 8 1

Output:
13
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e5+1;

// n: number of books, x: maximum moneyb
int n, x;
vector<int> price, page;
vector<vector<int>> f;

void input() {
    cin >> n >> x;

    price.resize(n+1);
    page.resize(n+1);
    f.resize(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }
}

void solve() {
    input();

    f[0][0] = 0;

    // i: i'th book
    // j: money
    // f[i][j]: maximum page that use j money to buy(doesn't buy) some books from 1-->i
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            int left = j - price[i];
            if (left < 0)
                f[i][j] = f[i-1][j];
            else
                f[i][j] = max(f[i-1][j], f[i-1][left] + page[i]);
        }
    }

    cout << f[n][x];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

/** RECURSION & MEMORIZE
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e5+1;
const int NONE = -1;
// n: number of books, x: maximum moneyb
int n, x;
vector<int> price, page;
vector<vector<int>> cached;

void input() {
    cin >> n >> x;

    price.resize(n+1);
    page.resize(n+1);
    cached.resize(x+1, vector<int>(n+1, NONE));

    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }
}

int solve(int maxMoney, int bookIdx) {
    if (bookIdx > n) return 0;
    if (maxMoney <= 0) return 0;
    if (cached[maxMoney][bookIdx] != NONE) return cached[maxMoney][bookIdx];

    if (maxMoney - price[bookIdx] < 0) return solve(maxMoney, bookIdx+1);

    int result = max(
        solve(maxMoney, bookIdx+1), 
        solve(maxMoney-price[bookIdx], bookIdx+1) + page[bookIdx]
    );
    cached[maxMoney][bookIdx] = result;
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    cout << solve(x, 1);

    return 0;
}
 */