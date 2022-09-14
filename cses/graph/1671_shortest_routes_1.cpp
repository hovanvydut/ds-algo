/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1671
 */

/* Test case
Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>

vector<vector<pii>> adjList;
vector<ll> dis;
vector<bool> visited;

const ll oo = LLONG_MAX;
ll n, m, u, v, w;

// min heap (ordered by first)
priority_queue<pii, vector<pii>, greater<pii>> pq;

void input() {
    cin >> n >> m;

    adjList.resize(n+1, vector<pii>());
    dis.resize(n+1, oo);
    visited.resize(n+1, false);
    
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        // u: source vertex, v: destination vertex, w: weight
        adjList[u].push_back({v, w});
    }
}

void solve() {
    input();

    dis[1] = 0;

    // first: distance, second: vertex
    pq.push({0, 1});

    while (!pq.empty()) {
        ll w = pq.top().first, u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (pii p : adjList[u]) {
            ll v = p.first, w = p.second;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}