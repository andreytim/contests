#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/*
	author - RoninFeng
*/

int solve() {
	int pos[2] = {1,1}, time[2] = {0,0}, N, res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char botC;
		int bot = 0, p;
		cin >> botC;
		cin >> p;
		if (botC == 'B') bot = 1;
		res = max(res, abs(pos[bot] - p) + time[bot]) + 1;
		pos[bot] = p;
		time[bot] = res;
	}
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
