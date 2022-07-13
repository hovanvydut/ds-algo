/**
 * @author hovanvydut
 * @problem https://www.spoj.com/problems/CONSEC/
 * Time Limited Exceeded
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;

class UnionFind {
private:
	vi parent;
	string S;
public:
	UnionFind(string str) {
		int maxNumSets = str.length();
		S = str;

		parent.assign(maxNumSets, -1);

		for (int it = 0; it < S.length(); it++) {
			parent[it] = it;
			if (it - 1 >= 0 && S[it-1] == S[it]) {
				parent[it] = parent[it-1];
			}
		}
	}

	int findSet(int i, int type) {
		if (type == 1) {
			if (parent[i] == -1)
				return 0;

			int consecutiveLetter = 1;
			int l = i - 1, r = i + 1;

			int isRunning = 2;
			while (isRunning > 0) {
				isRunning = 0;
				if (l >= 0 && parent[l] == parent[i]) {
					isRunning++;
					consecutiveLetter++;
					l--;
				}
				if (r < S.length() && parent[r] == parent[i]) {
					isRunning++;
					consecutiveLetter++;
					r++;
				}
			}
			return consecutiveLetter;
		} else if (type == 2) {
			S[i] = '#';
			parent[i] = -1;
			return -1;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, Q, i, type;
	string S;

	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cout << "Case " << ti << ":\n";

		cin >> S >> Q;
		UnionFind UF(S);
		for (int qi = 1; qi <= Q; qi++) {
			cin >> type >> i;
			int result = UF.findSet(i, type);
			if (result != -1) {
				cout << result << "\n";
			}
		}
	}
	return 0;
}