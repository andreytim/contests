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
	int N, currTime = 0, button, res = 0;
	char currColor = 0, prevColor = 0;
	map<char, int> position;
	position['O'] = 1; position['B'] = 1;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> currColor;
		cin >> button;
		if (currColor == prevColor || prevColor == 0) {
			currTime += abs(position[currColor] - button) + 1;
		} else {
			res += max(abs(position[currColor] - button), currTime) + 1;
			currTime = 0;
		}
		prevColor = currColor;
		position[currColor] = button;
	}

	return res + currTime;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T, N;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
