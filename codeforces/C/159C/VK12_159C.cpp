#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, char> pic;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int k, n, a;
	char c;
	string name;
	cin >> k;
	cin >> name;

	vector<int> v[200];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < name.length(); j++) {
			v[name[j]].push_back(j + i*name.length());
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		v[c].erase(v[c].begin() + a - 1);
	}

	vector<pic> m;
	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			m.push_back(make_pair(v[i][j], i));
		}
	}
	sort(m.begin(), m.end());

	for (int i = 0; i < m.size(); i++) {
		cout << m[i].second;
	}
	cout << endl;

	return 0;
}