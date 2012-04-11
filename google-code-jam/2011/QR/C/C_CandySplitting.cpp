#include <iostream>
#include <vector>

using namespace std;

/*
	author - RoninFeng
*/

void solve() {
	long long N, a, res = 0;
	cin >> N;
	vector<long long> c;
	
	cin >> res;
	long long sum = res, m = res;
	for (long long i = 1; i < N; i++) {
		cin >> a;
		res ^= a;
		m = min(m, a);
		sum += a;
	}

	if (res != 0) {
		cout << "NO";
	} else {
		cout << sum - m;
	}
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
