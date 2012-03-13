#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, i;
	cin >> n;
	unsigned char d[200];
	for (i = 0; i < 2*n; i++) cin >> d[i];
	sort(d, d+n);
	sort(d+n, d+2*n);
	string res = "NO";
	i = 0;
	while (i < n && d[i] < d[i+n]) i++;
	if (i == n) res = "YES";
	i = 0;
	while (i < n && d[i] > d[i+n]) i++;
	if (i == n) res = "YES";
	cout << res;
	return 0;
}