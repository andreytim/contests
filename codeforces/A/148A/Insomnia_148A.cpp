#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;

	vector<bool> dragons(100000, false);
	int res = 0;	

	for(int i = k-1; i < d; i += k) {
		if (!dragons[i]) {
			dragons[i] = true;
			res++;
		}
	}

	for(int i = l-1; i < d; i += l) {
		if (!dragons[i]) {
			dragons[i] = true;
			res++;
		}
	}

	for(int i = m-1; i < d; i += m) {
		if (!dragons[i]) {
			dragons[i] = true;
			res++;
		}
	}

	for(int i = n-1; i < d; i += n) {
		if (!dragons[i]) {
			dragons[i] = true;
			res++;
		}
	}

	cout << res;

	return 0;
}