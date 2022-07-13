/**
 * @author hovanvydut
 * @problem https://codeforces.com/contest/25/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void swap (int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

class UnionFind {
private:
	// rank is the height of tree
	vi parent, rank;
	int numSets;
public:
	UnionFind (int n) {
		parent.assign(n + 1, 0);
		rank.assign(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

		numSets = n;
	}

	int findSet (int i) {
		if (parent[i] == i)
			return i;
		parent[i] = findSet(parent[i]);
		return parent[i];
	}

	void unionSet (int i, int j) {
		int a = findSet(i);
		int b = findSet(j);
		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(rank[a], rank[b]);
			}
			parent[b] = a;

			if (rank[a] == rank[b]) {
				rank[a] += 1;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, a, b;
	vvi removeList, joinList;

	cin >> n;

	UnionFind UF(n);

	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		if (UF.findSet(a) == UF.findSet(b)) {
			removeList.push_back({a, b});
		} else {
			UF.unionSet(a, b);
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (UF.findSet(i) == UF.findSet(j))
				continue;
			UF.unionSet(i, j);
			joinList.push_back({i, j});
		}
	}

	cout << removeList.size() << "\n";
	for (int i = 0; i < removeList.size(); i++) {
		cout << removeList[i][0] << " " << removeList[i][1] << " " << joinList[i][0] << " " << joinList[i][1] << "\n";
	}

	return 0;
}