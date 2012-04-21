#include <conio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/*
	Finds the 5 biggest SCC's of directed graph.

	author - RoninFeng
*/

map<int, bool> visited;
vector<int> f, res;
int scc, N = 875714;

void dfsFoward(map<int, vector<int>>& outs, int v) {
	visited[v] = true;	
	scc++;
	for (int j = 0; j < outs[v].size(); j++) {
		if (!visited[outs[v][j]]) {
			dfsFoward(outs, outs[v][j]);
		}
	}
}

void findSCCs(map<int, vector<int>>& outs) {
	for (int i = f.size()-1; i >= 0; i--) {
		if (!visited[f[i]]) {
			scc = 0;
			dfsFoward(outs, f[i]);

			if (res.size() < 5) {
				res.push_back(scc);
				sort(res.rbegin(), res.rend());
			} else if (scc > res[4]) {
				res.pop_back();
				res.push_back(scc);
				sort(res.rbegin(), res.rend());
			}

		}
		cout << "forward left: " << i << endl;
	}
	while (res.size() < 5) res.push_back(0);
}

void dfsBack(map<int, vector<int>>& ins, int v) {
	visited[v] = true;
	for (int j = 0; j < ins[v].size(); j++) {
		if (!visited[ins[v][j]]) {
			dfsBack(ins, ins[v][j]);
		}
	}
	f.push_back(v);
}

void reverseLoop(map<int, vector<int>>& ins) {
	for (int i = N; i > 0; i--) {
		if (!visited[i]) {
			dfsBack(ins,i);
		}
		cout << "reverse left: " << i << endl;
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	
	map<int, vector<int>> ins;
	map<int, vector<int>> outs;
	int t = 0;
	while (!cin.eof()) {
		int v1, v2;
		cin >> v1 >> v2;
		ins[v2].push_back(v1);
		outs[v1].push_back(v2);
		cout << t++ << endl;
	}

	reverseLoop(ins);
	visited.clear();
	findSCCs(outs);

	for (int i = 0; i < 5; i++) {
		cout << res[i];
		if (i < 4)
			cout << ",";
	}

	getch();

	return 0;
}
