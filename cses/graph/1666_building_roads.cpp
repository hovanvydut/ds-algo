/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1666
 */

/* Test case
Input:
4 2
1 2
3 4

Output:
1
2 3
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_N = 1e5+1;
const int CONNECTED = 1;

int n, m;
bool visited[MAX_N];
vvi adjList(MAX_N);

void input() {
    cin >> n >> m;
    int r, c;
    for (int i = 1; i <= m; i++) {
        cin >> r >> c;
        adjList[r].push_back(c);
        adjList[c].push_back(r);
    }
}

void dfs(int v) {
    visited[v] = true;
    for (auto u : adjList[v]) {
        if (visited[u]) continue;
        dfs(u);
    }
}

void solve() {
    input();

    // v is vertex of graph
    int numConectedComponent = 0;
    vi headNode;

    for (int v = 1; v <= n; v++) {
        if (visited[v]) continue;
        dfs(v);
        numConectedComponent++;
        headNode.push_back(v);
    }

    // result
    cout << numConectedComponent - 1 << endl;
    if (numConectedComponent >= 2) {
        for (int i = 0; i < numConectedComponent - 1; i++) {
            cout << headNode[i] << " " << headNode[i+1] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}