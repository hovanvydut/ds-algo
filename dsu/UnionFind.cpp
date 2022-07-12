#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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
		parent.assign(n, 0);

		for (int i = 0; i <= n; i++) {
			parent[i] = 0;
			rank[i] = 1;
		}

		this.numSets = n;
	}

	int findSet (int i) {
		if (parent[i] === i)
			return i;
		return parent[i] = findSet(parent[i]);
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;

	cin >> n;
	UnionFind UF(n);

	for (int i = 1; i <= n; i++) {
		cin >> a; cin >> b;
		UF.unionSet(a, b);
	}

	
	return 0;
}