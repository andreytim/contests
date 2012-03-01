#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long long int64;

int main_Contrasts_131B() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int t[21];
	fill_n(t, 21, 0);
	int n, val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		t[val + 10]++;
	}

	int64 res = 0;
	for (int i = 0; i < 10; i++) {
		res += (int64)t[i]*(int64)t[20-i];
	}

	res += (int64)t[10]*((int64)t[10]-1)/2; 
	cout << res;

	return 0;
}