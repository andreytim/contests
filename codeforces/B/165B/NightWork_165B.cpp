#include <iostream>

using namespace std;

long long countNum(long long v, int div) {
	long long res = 0;
	while (v != 0) {
		res += v;
		v /= div;
	}
	return res;
}

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	long long n, k, lo = 0, hi;
	cin >> n >> k;
	hi = n;
	while (lo < hi) {
		long long mid = lo + (hi - lo)/2;
		if (countNum(mid, k) >= n) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	
	cout << hi;
	
	return 0;
}