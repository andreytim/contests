#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, i;
	cin >> n;
	vector<pair<int, int>> cards;

	for (i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cards.push_back(make_pair(b, a));
	}

	sort(cards.rbegin(), cards.rend());

	int counter = 1, res = 0;
	for (i = 0; i < n && counter > 0; i++) {
		res += cards[i].second;
		counter += cards[i].first - 1;
	}

	cout << res;

	return 0;
}