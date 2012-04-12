#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	author - RoninFeng
*/

void solve() {
	int N, temp[1000], arr[1000], res = 0;
	fill(temp, temp + 1000, INT_MAX);
	fill(arr, arr + 1000, INT_MAX);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		temp[i] = arr[i];
	}
	sort(arr, arr + 1000);
	for (int i = 0; i < N; i++) {
		if (arr[i] != temp[i]) {
			res++;
		}
	}
	cout << res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": "; 
		solve(); 
		cout << endl;
	}

	return 0;
}
