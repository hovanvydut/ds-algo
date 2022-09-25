/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1635
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
 
#define ll long long
#define vll vector<ll>
 
ll n, x;
vll c;
const int MOD = (int) 1e9 + 7;
 
// cache
vector<bool> ready;
vector<ll> cache;
 
void input() {
    cin >> n >> x;
 
    ready.resize(x+1, false);
    cache.resize(x+1, 0);
 
    ll t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        c.push_back(t);
    }
}
 
ll solve(ll x) {
    if (x == 0) return 1;
    if (x < 0) return 0;
 
    if (ready[x]) return cache[x];
 
    ll countWay = 0;
    for (ll ci : c) {
        countWay += solve(x-ci);
        countWay %= MOD;
    }
 
    ready[x] = true;
    cache[x] = countWay;
    return cache[x];
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    input();
    ll result = solve(x);
 
    cout << result;
 
    return 0;
}