/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1667
 */

/* Test case
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;


vvi input() {
    cin >> n >> m;
    vvi adjList(n+1);

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    return adjList;
}

void solve() {
    // adjency list
    vvi adjList = input();

    // bfs
    const int START_NODE = 1;
    const int END_NODE = n;
    const int NODE_NODE = 0;
    bool earlyStop = false;

    vector<bool> visited(n+1);
    vi parent(n+1);
    queue<int> nextVisitNode;

    nextVisitNode.push(START_NODE);
    visited[START_NODE] = true;
    parent[START_NODE] = NODE_NODE;

    while (!nextVisitNode.empty()) {
        if (earlyStop) break;

        int curentNode = nextVisitNode.front();
        nextVisitNode.pop();

        for (int neighborNode : adjList[curentNode]) {
            if (visited[neighborNode]) continue;
            visited[neighborNode] = true;
            nextVisitNode.push(neighborNode);
            parent[neighborNode] = curentNode;

            if (neighborNode == END_NODE) {
                earlyStop = true;
                break;
            }
        }
    }

    if (parent[END_NODE] == NODE_NODE) {
        cout << "IMPOSSIBLE";
        return;
    }

    vi path;
    int curNode = END_NODE;
    while (curNode != NODE_NODE) {
        path.push_back(curNode);
        curNode = parent[curNode];
    }

    cout << path.size() << endl;
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