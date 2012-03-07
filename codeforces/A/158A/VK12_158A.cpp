#include <iostream>
#include <vector>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, k, res = 0;
	cin >> n >> k;
	vector<int> m(n);
	for (int i = 0; i < n; i++) cin >> m[i];
	int i = 0;
	while (i < n && m[i] > 0 && m[i] >= m[k-1]) { res++; i++; }
	cout << res;
	return 0;
}