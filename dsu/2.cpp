/**
 * @author hovanvydut
 * @problem https://www.spoj.com/problems/CHAIN/
 */

// hint: use DSU, parent[i] = j means: j can eat i
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int countFalse = 0;

class UnionFind {
public:
	vi parent;
	int numSets;
	UnionFind(int n) {
		numSets = n;
		parent.assign(n+1, -1);
	}

	int findSet(int i) {
		return parent[i];
	}

	void unionSets(int x, int y, int ki) {
		if (parent[x] == -1 && parent[y] == -1) {
			parent[x] = 0; // A
			parent[y] = 1; // B
		} else if (parent[x] == -1 || parent[y] == -1) {
			if (parent[x] == -1) {
				parent[x] = parent[y] - 1 >= 0 ? parent[y] - 1 : 2;
			} else {
				parent[y] = (parent[x] + 1) % 3;
			}
		} else {
			if (parent[x] == 0 && parent[y] == 2) {
				cout << ki << " false\n";
				countFalse++;
				return;
			}
			if (parent[x] == 2 && parent[y] ==0) {
				return;
			}
			if (parent[x] > parent[y]) {
				cout << ki << " false\n";
				countFalse++;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, k, d, x, y;
	cin >> t;

	for (int ti = 1; ti <= t; ti++) {
		countFalse = 0;
		cin >> n >> k;
		UnionFind UF(n);

		for (int ki = 1; ki <= k; ki++) {
			cin >> d >> x >> y;

			if (x > n || y > n || x < 1 || y < 1) {
				cout << ki << " false\n";
				countFalse++;
				continue;
			}


			if (d == 1) {
				if (x == y) continue;
				int kindX = UF.findSet(x);
				int kindY = UF.findSet(y);
				if (kindX != -1 && kindY != -1) {
					if (kindX != kindY) {
						cout << ki << " false\n";
						countFalse++;
						continue;
					}
				} else if (kindX == -1 && kindY == -1) {
					UF.parent[x] = 0;
					UF.parent[y] = 0;
				} else if (kindX == -1 && kindY != -1) {
					UF.parent[x] = kindY;
				} else if (kindX != -1 && kindY == -1) {
					UF.parent[y] = kindX;
				}
			} else if (d == 2) {

				if (x == y) {
					cout << ki << " false\n";
					countFalse++;
					continue;
				}

				UF.unionSets(x, y, ki);
			}
		}
				for (int i = 1; i <= 10; i++) {
					cout << UF.parent[i] << "\t";
				}
				cout << endl;
				for (int i = 1; i <= 10; i++) {
					cout << i << "\t";
				}
		cout << countFalse << "\n";
	}

	return 0;
}