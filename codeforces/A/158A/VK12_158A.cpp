#include <iostream>
#include <vector>
using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n,k, res = 0;
	cin >> n >> k;
	vector<int> m(n);
	for (int i = 0; i < n; i++) { cin >> m[i]; }
	int i = 0, count = 0;
	while (m[i] != 0 && count <= k) {

	}
	cout << res;
	return 0;
}