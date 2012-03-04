#include <vector>
#include <iostream>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n;
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		int idx;
		cin >> idx;
		res[idx-1] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << res[i]+1 << ' ';
	}
	return 0;
}