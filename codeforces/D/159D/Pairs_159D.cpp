#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 2000;

int main() {
	//freopen("input.txt", "wt", stdout);
	//for (int k = 0; k < 2000; k++) cout << 'z';

	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int i, j, x, y;
	string s;
	cin >> s;
	int L = s.length();

	vector<long long> less(N, 0), greater(N, 0);
	for (i = 0; i < L; i++) {
		for (x = y = i; x >= 0 && y < L && s[x] == s[y]; x--, y++) {
			less[y]++; 
			greater[x]++;
		}

		for (x = i, y = i + 1; x >= 0 && y < L && s[x] == s[y]; x--, y++) {
			less[y]++; 
			greater[x]++;
		}
	}

	long long res = 0;
	for (i = 0; i < L-1; i++) {
		y = L-1;
		long long g = 0;
		while (y > i) { g += greater[y]; y--; }
		res += less[i]*g;
	}

	cout << res;

	return 0;
}