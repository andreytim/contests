#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

/*
	Finds the number of crossing edges in the minimum cut of the graph
	through invoking the Randomized Contraction Algorithm for N*N times.

	author - RoninFeng
*/

map<int, bool> visited;
vector<int> sccs, f;
stack<int> s, ts;
int scc, t = 0;

void dfsFoward(map<int, vector<int>>& outs) {
	while (!s.empty()) {
		int v = s.top(); s.pop();
		for (int j = 0; j < outs[v].size(); j++) {
			if (!visited[outs[v][j]]) {
				visited[outs[v][j]] = true;
				s.push(outs[v][j]);
			}
		}
		scc++;
	}
}

void findSCCs(map<int, vector<int>>& outs) {
	for (int i = f.size()-1; i >= 0; i--) {
		int v = f[i];
		if (!visited[v]) {
			scc = 0;
			visited[v] = true;
			s.push(v);
			dfsFoward(outs);
			sccs.push_back(scc);
		}
	}
}

void dfsBack(map<int, vector<int>>& ins) {
	while (!s.empty()) {
		int v = s.top(); s.pop();
		for (int j = 0; j < ins[v].size(); j++) {
			if (!visited[ins[v][j]]) {
				visited[ins[v][j]] = true;
				s.push(ins[v][j]);
				ts.push(ins[v][j]);
			}
		}
	}
}

void reverseLoop(int N, map<int, vector<int>>& ins) {
	for (int i = N; i > 0; i--) {
		if (!visited[i]) {
			visited[i] = true;
			s.push(i);
			ts.push(i);
			dfsBack(ins);
			while (!ts.empty()) {
				f.push_back(ts.top());
				ts.pop();
			}
		}
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

	reverseLoop(875714, ins);
	visited.clear();
	findSCCs(outs);

	sort(sccs.rbegin(), sccs.rend());

	freopen("output.txt", "wt", stdout);
	for (int i = 0; i < 5 && i < sccs.size(); i++) {
		cout << sccs[i];
		if (i < 4 && i < sccs.size()-1)
			cout << ",";
	}

	return 0;
}
