#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <sstream>

using namespace std;

inline int gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a == 0 || b == 0) {
		return a | b;
	}
	int shift;
	for (shift = 0; ((a | b) & 1) == 0; shift++) {
		a >>= 1;
		b >>= 1;
	}
	while ((a & 1) == 0) {
		a >>= 1;
	}
	do {
		while ((b & 1) == 0) {
			b >>= 1;
		}
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		b = b - a;
	} while (b != 0);
	return a << shift;
}

int main_Epic_119A() {
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