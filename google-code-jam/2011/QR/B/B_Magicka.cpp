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

void solve() {
	int C, D, N, i, j;
	char a, b, c, prev;

	cin >> C;
	vector<vector<char>> combs(256, vector<char>(256, '-'));
	for (i = 0; i < C; i++) {
		cin >> a >> b >> c;
		combs[a][b] = c;
		combs[b][a] = c;
	}

	cin >> D;
	vector<vector<bool>> opps(256, vector<bool>(256, false));
	for (i = 0; i < D; i++) {
		cin >> a >> b;
		opps[a][b] = true;
		opps[b][a] = true;
	}

	cin >> N;
	vector<char> res;
	cin >> c;
	res.push_back(c);
	prev = c;	
	for (i = 1; i < N; i++) {
		cin >> c;
		char temp = combs[prev][c];
		if (temp != '-') {
			res.pop_back();
			res.push_back(temp);
			prev = temp;
		} else {
			for (j = 0; j < res.size(); j++) {
				if (opps[c][res[j]]) {
					res.clear();
					if (++i < N) {
						cin >> c;
					}
					break;
				}
			}
			if (i < N) {
				res.push_back(c);
				prev = c;
			}
		}
	}

	cout << "[";
	for (i = 0; i < res.size(); i++) {
		if (i > 0) cout << ", ";
		cout << res[i];
	}
	cout << ']';
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": "; 
		solve(); 
		cout << endl;
	}

	return 0;
}
