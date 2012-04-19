#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

/*
	Finds the number of crossing edges in the minimum cut of the graph
	through invoking the Randomized Contraction Algorithm for N*N times.

	author - RoninFeng
*/

map<int, bool> visited;
vector<pair<int,int>> f;
vector<int> sccs, stack;
int scc, t = 0;

void dfsFoward(map<int, vector<int>>& outs) {
	while (!stack.empty()) {
		int v = stack.back();
		stack.pop_back();
		for (int j = 0; j < outs[v].size(); j++) {
			if (!visited[outs[v][j]]) {
				visited[outs[v][j]] = true;
				stack.push_back(outs[v][j]);
			}
		}
		scc++;
	}
}

void findSCCs(map<int, vector<int>>& outs) {
	for (int i = 0; i < f.size(); i++) {
		if (!visited[f[i].second]) {
			scc = 0;
			visited[f[i].second] = true;
			stack.push_back(f[i].second);
			dfsFoward(outs);
			sccs.push_back(scc);
		}
	}
}

void dfsBack(map<int, vector<int>>& ins) {
	while (!stack.empty()) {
		int v = stack.back();
		stack.pop_back();
		for (int j = 0; j < ins[v].size(); j++) {
			if (!visited[ins[v][j]]) {
				visited[ins[v][j]] = true;
				stack.push_back(ins[v][j]);
			}
		}
		t++;
		f.push_back(pair<int,int>(t,v));
	}
}

void reverseLoop(int N, map<int, vector<int>>& ins) {
	for (int i = N; i > 0; i--) {
		if (!visited[i]) {
			visited[i] = true;
			stack.push_back(i);
			dfsBack(ins);
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

	reverseLoop(11, ins);

	visited.clear();
	stack.clear();
	sort(f.rbegin(), f.rend());

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
