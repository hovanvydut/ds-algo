/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1193
 */

/* Test case
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 1e3+10;
const int WALL = 0;
const int FLOOR = 1;

int startR, startC, endR, endC;
int n, m;

int grid[MAX_N][MAX_N];
pii parent[MAX_N][MAX_N];

// top right bottom left
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};

void input() {
    char ch;
    for (int r=0; r<n; r++) {
        for (int c=0; c<m; c++) {
            cin >> ch;

            if (ch == '#') {
                grid[r][c] = WALL;
            }
            
            if (ch == '.') {
                grid[r][c] = FLOOR;
            }

            if (ch == 'A') {
                grid[r][c] = FLOOR;
                startR = r; startC = c;
            }

            if (ch == 'B') {
                grid[r][c] = FLOOR;
                endR = r; endC = c;
            }
        }
    }
}

char direction(pii A, pii B) {
    if (A.first == B.first) {
        if (B.second > A.second) {
            return 'R';
        } else {
            return 'L';
        }
    }

    if (A.second == B.second) {
        if (B.first > A.first) {
            return 'D';
        } else {
            return 'U';
        }
    }

}

bool isPosibble(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    if (grid[r][c] == WALL) return false;
    return true;
}

bool bfs(int r, int c) {
    queue<pii> nextVisitNode;
    bool hasPath = false;

    nextVisitNode.push({r, c});
    parent[r][c] = {-1, -1};
    // mark visited
    grid[r][c] = WALL;

    while (!nextVisitNode.empty()) {
        pii curNode = nextVisitNode.front();
        nextVisitNode.pop();

        int x = curNode.first, y = curNode.second;

        for (int i=0; i<4; i++) {
            int new_dr = x + dr[i];
            int new_dc = y + dc[i];

            if (!isPosibble(new_dr, new_dc)) continue;

            nextVisitNode.push({new_dr, new_dc});
            parent[new_dr][new_dc] = {x, y};
            // mark visited
            grid[new_dr][new_dc] = WALL;

            // early stop bfs
            if (new_dr == endR && new_dc == endC) {
                hasPath = true;
                break;
            }
        }
    }

    return hasPath;
}

void solve() {
    cin >> n >> m;
    input();

    bool hasPath = bfs(startR, startC);
    if (!hasPath) {
        cout << "NO";
        return;
    }

    cout << "YES" << endl;
    int r = endR, c = endC, lenPath = 0;
    string directionStr = "";

    while (parent[r][c].first != -1 && parent[r][c].second != -1) {
        lenPath++;
        directionStr += direction(parent[r][c], {r, c});
        int r2 = parent[r][c].first, c2 = parent[r][c].second;
        r = r2, c = c2;
    }

    reverse(directionStr.begin(), directionStr.end());
    cout << lenPath << endl;
    cout << directionStr;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}