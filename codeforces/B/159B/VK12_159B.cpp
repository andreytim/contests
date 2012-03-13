#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FOR(i, start, end) for (i = start; i < end; i++)

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, m, i, j, x, y;
	vector< vector<int> > f(1000, vector<int>(1000, 0)), c(1000, vector<int>(1000, 0));
	cin >> n >> m;

	FOR(i, 0, n) { cin >> x >> y; f[y-1][x-1]++; }
	FOR(i, 0, m) { cin >> x >> y; c[y-1][x-1]++; }

	int res1 = 0, res2 = 0;
	FOR(i, 0, 1000) {
		int freeF = 0, freeC = 0;
		FOR(j, 0, 1000) {
			if (c[i][j] - f[i][j] > 0) {
				res1 += f[i][j];
				res2 += f[i][j];
				freeC += c[i][j] - f[i][j];
			} else if (f[i][j] - c[i][j] > 0) {
				res1 += c[i][j];
				res2 += c[i][j];
				freeF += f[i][j] - c[i][j];
			} else {
				res1 += c[i][j];
				res2 += c[i][j];
			}
		}
		res1 += min(freeC, freeF);
	}

	cout << res1 << ' ' << res2;

	return 0;
}