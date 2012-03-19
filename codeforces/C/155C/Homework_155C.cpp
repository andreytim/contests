#include <iostream>
#include <string>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	string s, p;
	int k, res = 0;
	cin >> s >> k;
	for (int i = 0; i < k; i++) {
		cin >> p;
		int a = 0, b = 0;
		for (int j = 0; j < s.length(); j++) {
			if (p[0] == s[j]) { a++; }
			else if (p[1] == s[j]) { b++; }
			else {
				res += min(a,b); a = 0; b = 0;
			}
		}
		res += min(a,b);
	}

	cout << res;

	return 0;
}