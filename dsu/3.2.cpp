/**
 * @author hovanvydut
 * @problem https://www.spoj.com/problems/CONSEC/
 * Accepted
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define limit 100100

class UnionFind {
public:
	vi parent;
	vi rank;
	string S, SS;
	int maxNumSets;

	UnionFind(string str) {
		S = str;
		SS = str;

		maxNumSets = S.length();
		parent.assign(maxNumSets, 0);
		rank.assign(maxNumSets, 0);

		for (int i = 0; i < maxNumSets; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int findSet(int a) {
		if (parent[a] == a) {
			return parent[a];
		}
		return (parent[a] = findSet(parent[a]));
	}

	void unionSets(int a, int b) {
		int pa = findSet(a);
		int pb = findSet(b);
		if (pa != pb) {
			parent[pb] = pa;
			rank[pa] += rank[pb];
		}
	}
};

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	int T, Q, type, i;
	string S;
	pii qr[limit];
	int ans[limit];

	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cout << "Case " << ti << ":\n";

		cin >> S >> Q;

		UnionFind UF(S);
		for (int qi = 1; qi <= Q; qi++) {
			cin >> qr[qi].first >> qr[qi].second;
			if (qr[qi].first == 2) {
				UF.S[qr[qi].second] = '#';
			}
		}

		for (int i = 1; i < UF.maxNumSets; i++) {
			if (UF.S[i] != '#' && UF.S[i] == UF.S[i - 1]) {
				UF.unionSets(i, i - 1);
			}
		}

		int ansCount = 0;
		for (int qi = Q; qi >= 1; qi--) {
			type = qr[qi].first;
			i = qr[qi].second;

			if (type == 1) {
				ans[ansCount++] = UF.rank[UF.findSet(i)];
			} else if (type == 2) {
				UF.S[i] = UF.SS[i];

				if (i + 1 < UF.maxNumSets && UF.S[i] == UF.S[i+1]) {
					UF.unionSets(i, i + 1);
				}

				if (i - 1 >= 0 && UF.S[i] == UF.S[i-1]) {
					UF.unionSets(i, i - 1);
				}
			}
		}

		for (int qi = ansCount-1; qi >= 0; qi--) {
			cout << ans[qi] << "\n";
		}
	}
	return 0;
}