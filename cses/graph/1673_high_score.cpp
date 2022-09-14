/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1673
 */
 
/* Test case
Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
 
Output:
5
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct triple {
    ll from;
    ll to;
    ll cost;
};
 
ll n, m, a, b, x;
vector<triple> edges;
vector<ll> dis;
const ll NEG_INF = LLONG_MIN;
vector<bool> negative_cycle_node;
vector<ll> parent;
vector<vector<ll>> reverseAdjList;
vector<bool> visited;
 
void input() {
    cin >> n >> m;
 
    dis.resize(n+1, NEG_INF);
    parent.resize(n+1, -1);
    reverseAdjList.resize(n+1, vector<ll>());
    visited.resize(n+1, false);
    negative_cycle_node.resize(n+1, false);
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        reverseAdjList[b].push_back(a);
    }
}
 
void print_dis() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
    };
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << "\t";
    };
    cout << endl;
}

void dfs(ll node) {
    visited[node] = true;

    for (ll reverseNeighborNode : reverseAdjList[node]) {
        if (visited[reverseNeighborNode]) continue;
        dfs(reverseNeighborNode);
    }
}
 
// use bellman ford for find the largest path
void bellmanFord() {

    // use dfs with reverse adjency list
    dfs(n);

    // loop 1 --> n-1: find the largest distance
    // loop n: to find the nodes in the negative cycle
    for (int i = 1; i <= n; i++) {
        bool earlyStop = true;
        for (auto edge : edges) {
            if (dis[edge.from] != NEG_INF 
                && dis[edge.from] + edge.cost > dis[edge.to]) {
                dis[edge.to] = dis[edge.from] + edge.cost;
                earlyStop = false;

                // if has any node in negative cycle and directly or indirectly go to node n
                // then return -1
                if (i == n && visited[edge.to]) {
                    cout << -1;
                    return;
                }

                parent[edge.to] = edge.from;
            }
        }
        if (earlyStop) break;
    }

    cout << dis[n];
}
 
void solve() {
    input();
    dis[1] = 0;
    bellmanFord();
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}