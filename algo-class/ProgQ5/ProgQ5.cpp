#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
	Check if some of two ints in input gives in sum the member of sums array.

	author - RoninFeng
*/

vector<int> vi;
map<int, bool> ints;
int sums[9] = { 231552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379 };
int N = 100000, i, j;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	for (i = 0; i < N; i++) {
		int a;
		cin >> a;
		vi.push_back(a);
		ints[a] = true;
	}

	string res = "";
	for (i = 0; i < 9; i++) {
		for (j = 0; j < N; j++) {
			if (ints[sums[i] - vi[j]]) {
				res.append("1");
				break;
			}
		}
		if (j == N)
			res.append("0");
	}

	cout << res;

	return 0;
}
