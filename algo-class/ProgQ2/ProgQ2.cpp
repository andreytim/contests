#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000;

// p = l => 162085
// p = r => 164123
// p = median => 138382

int choosePivot(vector<int>& a, int l, int r) {
	int min = l, max = r, mid = (r + l)/2;
	if (a[min] > a[max]) swap(min, max);
	if (a[min] > a[mid]) 
		return min;
	else if (a[max] < a[mid])
		return max;
	return mid;
}

int partition(vector<int>& a, int l, int r, int p) {
	swap(a[p], a[l]);
 	int i = l + 1;
	for (int j = i; j <= r; j++) {
		if (a[j] < a[l]) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[l], a[i-1]);
	return i-1;
}

long long quickSort(vector<int>& a, int l, int r) {
	long long res = 0;
	if (r > l) {
		int p = choosePivot(a, l, r);
		int i = partition(a, l, r, p);
		res += r - l + quickSort(a, l, i-1) + quickSort(a, i+1, r);
	}
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	cout << quickSort(a, 0, N-1);
	
	return 0;
}
