/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1621
 */

/* Test case
Input:
5
2 3 2 2 3

Output:
2
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int x;
    set<int> s;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;

    return 0;
}