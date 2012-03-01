#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main_Trace_157B() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	const double PI = 3.141592653589793;

	int N;
	cin >> N;

	vector<int> rads(N);
	for (int i = 0; i < N; i++) {
		cin >> rads[i];
	}
	sort(rads.begin(), rads.end());
	
	vector<double> squares(N);
	for(int i = 0; i < N; i++) {
		squares[N-i-1] = rads[i]*rads[i]*PI;
	}

	double res = 0;
	for(int i = 0; i < N; i++) {
		int sign = -1;
		if ((i & 1) == 0) {
			sign = 1;
		}
		res = res + sign*squares[i];
	}

	cout.precision(10);
	cout << res;

	return 0;
}