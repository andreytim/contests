#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int a, b, n;
	cin >> a >> b >> n;
	int count = 0;
	while (n > 0) {
		if ((count & 1) == 0) {
			n = n - gcd(a, n);
		} else {
			n = n - gcd(b, n);
		}
		count++;
	}

	if ((count & 1) == 0) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}