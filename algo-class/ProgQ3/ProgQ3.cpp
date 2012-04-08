#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 40;

int minCut(vector<pair<int,int>> edges) {
	int count = N;
	while (count > 2) {
		int e = rand() % edges.size();
		int f = edges[e].first, s = edges[e].second;
		count--;
		vector<pair<int,int>> newEdges, temp;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].first == s) {
				edges[i].first = f;
			}
			if (edges[i].second == s) {
				edges[i].second = f;
			}
			if (edges[i].second != edges[i].first)
				newEdges.push_back(edges[i]);
		}
		edges.clear();
		swap(edges, newEdges);
	}
	return edges.size();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	string temp;
	int v;
	set<pair<int,int>> edges;
	for (int i = 0; i < N; i++) {
		stringstream ss;
		getline(cin, temp);
		ss << temp << " -1"; 
		ss >> v;
		for (ss >> v; v != -1; ss >> v) {
			edges.insert(make_pair(min(i,v-1), max(i,v-1)));
		}
	}
	
	int mc = N*(N-1)/2;
	vector<pair<int,int>> ve = vector<pair<int,int>>(edges.begin(), edges.end());
	for (int i = 0; i < N*N; i++) {
		mc = min(minCut(ve), mc);
	}
	cout << mc;

	return 0;
}
