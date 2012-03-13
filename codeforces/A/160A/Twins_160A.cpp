#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, c[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	sort(c, c+n);
	int i = 0, j = n-1, sumF = 0, sumL = c[n-1], res = 1;
	while (i < j) {
		sumF += c[i];
		i++;
		if (sumF >= sumL) {
			j--;
			sumL += c[j];
			res++;
		}
	}

	cout << res;

	return 0;
}