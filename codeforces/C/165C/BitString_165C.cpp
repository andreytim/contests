#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	long long n, k;
	cin >> n >> k; k--;
	vector<long long> vll(n);
	for (int i = 0; i < n; i++) cin >> vll[i];
	sort(vll.begin(), vll.end());
	long long i = k/n, num1 = 0, num2 = 0, idx = 0;
	while (vll[idx] < vll[i]) idx++; num1 = idx;
	while (idx < n && vll[idx] == vll[i]) idx++; num2 = idx - num1;
	long long j = (k - n*num1)/num2;
	cout << vll[i] << ' ' << vll[j];
	return 0;
}