#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool checkWin(const vector< vector<int> > &v, int x, int y) {
	int resVert = 0, resHor = 0;
	for (int i = 0; i < v.size(); i++) {
		resVert += v[i][y];
	}
	for (int i = 0; i < v.size(); i++) {
		resHor += v[x][i];
	}
	return resVert > resHor;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int N;
	cin >> N;
	vector< vector<int> > v(N, vector<int>(N));
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			cin >> v[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			if (checkWin(v, i, j)) {
				res++;
			}
		}
	}

	cout << res;
	return 0;
}