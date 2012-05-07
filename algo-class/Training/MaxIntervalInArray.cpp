#include <iostream>

using namespace std;

const int n = 10;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int arr[n];
	int imax = -1, jmax = -1, Smax = INT_MIN, i, j, S = 0; 
	for (j = 0; j < n; j++) cin >> arr[j];
	for (j = 0; j < n; j++) {
		if (S == 0) {	
			i = j;
		}
		S += arr[j];
		if (S > Smax) {
			Smax = S; jmax = j; imax = i;
		}
		if (S < 0) {
			S = 0;
		}
	}

	cout << "interval: [" << imax << "," << jmax << "], sum: " << Smax;

	return 0;
}