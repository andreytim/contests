#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	author - RoninFeng
*/

void solve() {
	int n, i, a;
	vector<long long> x, y;
	long long res = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		x.push_back(a);
	}
	for (i = 0; i < n; i++) {
		cin >> a;
		y.push_back(a);
	}
	sort(x.begin(), x.end());
	sort(y.rbegin(), y.rend());
	for (i = 0; i < n; i++) {
		res += x[i]*y[i];
	}
	cout << res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": "; 
		solve(); 
		cout << endl;
	}

	return 0;
}