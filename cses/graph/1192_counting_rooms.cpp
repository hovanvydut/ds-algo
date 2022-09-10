/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1192
 */

/* Test case
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
 */

#include <bits/stdc++.h>
using namespace std;
int WALL = 0;
int FLOOR = 1;

void dfs(vector<vector<int>> &map, int &r, int &c, int &n, int &m) {
	// top right bottom left
	
	// mark visited
	map[r][c] = WALL;

	int dr[] = {-1, 0, +1, 0};
	int dc[] = {0, +1, 0, -1};

	for (int i=0; i<4; i++) {
		int new_dr = r + dr[i];
		int new_dc = c + dc[i];

		// check can go to the next floor
		if (new_dr < 0 || new_dr >= n || new_dc < 0 || new_dc >= m) continue;
		if (map[new_dr][new_dc] == WALL) continue;

		dfs(map, new_dr, new_dc, n, m);
	}
}

void input(int &n, int &m, vector<vector<int>> &map) {
	for (int r=0; r<n; r++) {
		vector<int> row;
		map.push_back(row);
		char ch;
		for (int c=0; c<m; c++) {
			cin >> ch;
			if (ch == '#') map[r].push_back(WALL);
			if (ch == '.') map[r].push_back(FLOOR);
		}
	}
}

void solve(int n, int m) {
	vector<vector<int>> map;
	input(n, m, map);

	int numRoom = 0;

	for (int r=0; r<n; r++) {
		for (int c=0; c<m; c++) {
			if (map[r][c] == WALL) continue;
			dfs(map, r, c, n, m);
			numRoom++;
		}
	}
	cout << numRoom;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	solve(n, m);

	return 0;
}