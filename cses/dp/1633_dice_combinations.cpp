/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1633
 */
 
/**
Input:
3

Output:
4
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<ll>

ll n;
vll ready, cache;
const int MOD = (int) 1e9 + 7;

void input() {
    cin >> n;
    ready.resize(n+1, false);
    cache.resize(n+1, 0);
}
 
ll solve(ll x) {
    if (x == 0) return 1;
    if (x < 0) return 0;

    if (ready[x]) return cache[x];

    ll countWay = 0;
    for (ll dice = 1; dice <= 6; dice++) {
        countWay += solve(x - dice);
        countWay %= MOD;
    };

    ready[x] = true;
    cache[x] = countWay;
    return countWay;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    input();
    ll result = solve(n);
 
    cout << result;
 
    return 0;
}