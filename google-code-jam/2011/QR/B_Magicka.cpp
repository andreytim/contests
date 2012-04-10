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

string solve() {
	int i;
	map<char, char> opps;
	map<pair<char, char>, char> nbs;
	
	int C, D, N;
	cin >> C;
	for (i = 0; i < C; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		nbs[make_pair(a, b)] = c;
		nbs[make_pair(b, a)] = c;
	}

	cin >> D;
	for (i = 0; i < C; i++) {
		char a, b;
		cin >> a >> b;
		opps[a] = b;
		opps[b] = a;
	}

	cin >> N;
	vector<char> res;
	char c; cin >> c;
	res.push_back(c);
	for (i = 1; i < N; i++) {
		cin >> c;
		if (nbs.find(make_pair(res[i-1], c)) != nbs.end()) {
			res.pop_back();
			res.push_back(nbs[make_pair(res[i-1], c)]);
		} else if (opps.find(c) != opps.end() && find(res.begin(), res.end(), opps[c]) != res.end()) {
			res.clear();
		} else {
			res.push_back(c);
		}
	}

	string resS = "[";
	for (i = 0; i < res.size(); i++) {
		if (i > 0) resS.append(", ");
		resS += res[i];
	}
	resS += ']';
	return resS;
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
