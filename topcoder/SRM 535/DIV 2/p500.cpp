#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	long long L, G, res, min;
	cin >> G >> L;
	if (L%G != 0) {
		cout << -1; return 0;
	}

	res = 1;
	while (L%G == 0) {
		res *= G;
		L /= G;
	}

	cout << res + L/res;

	return 0;
}