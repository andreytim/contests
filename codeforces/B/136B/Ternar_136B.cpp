#include <iostream>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	long a,c;
	cin >> a >> c;

	long res = 0;
	int t = 1;
	while (a != 0 || c != 0) {
		res += ((c%3 - a%3 + 3)%3)*t;
		t *= 3;
		c /= 3;
		a /= 3;
	}

	cout << res;

	return 0;
}