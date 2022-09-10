/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1668
 */

/* Test case
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int NO_COLOR = -1;
const int RED = 1;
const int BLUE = 2;

int n, m, a, b;
vector<bool> visited;
vector<int> colored;
bool imposibble = false;

vvi input() {
    cin >> n >> m;

    vvi adjList(n+1);
    visited.assign(n+1, false);
    colored.assign(n+1, NO_COLOR);

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    return adjList;
}

int genNextColor(int color) {
    if (color == RED) {
        return BLUE;
    }

    if (color == BLUE) {
        return RED;
    }
}

void dfs(vvi &adjList, int v, int color) {
    if (imposibble) return;

    visited[v] = true;
    colored[v] = color;

    for (int u : adjList[v]) {
        if (visited[u]) {
            if (colored[u] != NO_COLOR && colored[v] == colored[u]) {
                imposibble = true;
                return;
            }
            continue;
        }
        dfs(adjList, u, genNextColor(color));
    }

}

void solve() {
    vvi adjList = input();

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(adjList, i, RED);
    }

    // result
    if (imposibble) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << colored[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}