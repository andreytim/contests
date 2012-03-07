#include <iostream>
using namespace std;

//void genTestCase() {
//	cout << 1 << endl;
//	for (int i = 0; i < 100000; i++) {
//		cout << 1 << ' ';
//	}
//}

int main() {
	//freopen("input.txt", "wt", stdout);
	//genTestCase();

	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, res = 0, p[4] = {0,0,0,0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 4) res++;
		else p[a]++;
	}
	p[1] = max(p[1] - p[3],0);
	if ((p[2] & 1) != 0) {
		p[1] = max(p[1]-2,0);
		p[2]++;
	}
	p[2] /= 2;
	if (p[1]%4 > 0) 
		p[1] = p[1]/4 + 1;
	else 
		p[1] = p[1]/4;
	cout << res + p[1] + p[2] + p[3];

	return 0;
}