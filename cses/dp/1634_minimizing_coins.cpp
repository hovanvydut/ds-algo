/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1634
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

ll n, x;
vll c;
ll INF = 1e10;

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
    if (x < 0) return INF;
    if (x == 0) return 0;

    // use cache
    if (ready[x]) return cache[x];

    ll best = INF;
    for (ll ci : c) {
        best = min(best, 1 + solve(x-ci));
    }

    ready[x] = true;
    cache[x] = best;
    return best;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    ll result = solve(x);

    if (result >= INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}