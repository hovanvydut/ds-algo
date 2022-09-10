/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1669
 */

/* Test case
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

const int NO_NODE = -1;

int n, m, a, b;
vb visited;
vi parent;
int cycle_start = -1;
int cycle_end = -1;

vvi input() {
    cin >> n >> m;

    // init
    vvi adjList(n+1);
    visited.assign(n+1, false);
    parent.assign(n+1, NO_NODE);

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    return adjList;
}

bool dfs(vvi &adjList, int v, int parentNodeV) {
    visited[v] = true;

    for (int u : adjList[v]) {
        // skipping edge to parent vertex
        if (u == parentNodeV) continue;
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }

        parent[u] = v;
        if (dfs(adjList, u, parent[u])) {
            return true;
        };
    }

    return false;
}

void solve() {
    vvi adjList = input();

    for (int v= 1; v <= n; v++) {
        if (visited[v]) continue;
        if (dfs(adjList, v, parent[v])) {
            break;
        };
    }

    // result
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE";
        return;
    }

    vi path;
    path.push_back(cycle_start);
    int lenPath = 1;
    int tmp_node = cycle_end;
    while (tmp_node != cycle_start) {
        lenPath++;
        path.push_back(tmp_node);
        tmp_node = parent[tmp_node];
    }
    path.push_back(cycle_start);


    cout << lenPath+1 << endl;
    reverse(path.begin(), path.end());
    for (int node : path) {
        cout << node << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}