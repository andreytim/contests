#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	long long k, res = 0;
	string s;
	cin >> k >> s;
	map<int, int> counts; 
	counts[0] = 1;
	int curr = 0;
	for (int i = 0; i < s.length(); i++) {
		curr += s[i] - '0';
		if (curr - k >= 0) {
			res += counts[curr - k];
		}
		counts[curr]++;
	}
	cout << res;

	return 0;
}