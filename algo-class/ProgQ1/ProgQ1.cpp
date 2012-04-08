#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;

/*	
	Counts the number of inversions in the array through Merge Sort algorithm.

	author - RoninFeng
*/

long long mergeWithCount(vector<int> &a, int l, int r) {
	vector<int> result;
	int mid = (l + r) / 2, 
		i = l, 
		j = mid + 1, 
		size = r - l + 1;
	long long count = 0;
	for (int k = 0; k < size; k++) {
		if (j > r || i <= mid && a[i] < a[j]) {
			result.push_back(a[i]);
			i++;
		} else {
			result.push_back(a[j]);
			j++;
			if (i <= mid) count += mid - i + 1;
		}
	}
	for (i = l; i <= r; i++) a[i] = result[i-l];
	return count;
}

long long sortWithCount(vector<int> &a, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		int x = sortWithCount(a, l, mid);
		int y = sortWithCount(a, mid + 1, r);
		return x + y + mergeWithCount(a, l, r);
	}
	return 0;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	cout << sortWithCount(a, 0, N-1);
	
	return 0;
}
