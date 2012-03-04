#include <iostream>
using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int a, n, max, min, res = 0;
	cin >> n >> max;
	min = max;
	for (int i = 0; i < n-1; i++) {
		cin >> a;
		if (a > max) {
			res++;
			max = a;
		} else if (a < min) {
			res++;
			min = a;
		}
	}
	cout << res;
	return 0;
}