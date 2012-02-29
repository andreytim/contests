#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <class T>
inline string toString (const T& t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

string genString(int n) {
	string res;
	for (int i = 0; i < n+1; i++) {
		res += toString(i) + ' ';
	}
	for (int i = n-1; i >= 0; i--) {
		res += toString(i) + ' ';
	}
	return res.substr(0, res.length()-1);
}

int main_Gift_118B() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int N;
	cin >> N;

	vector<string> strings(N+1);

	for (int i = 0; i < N+1; i++) {
		strings[i] = genString(i);
	}
	
	for (int i = 0; i < N+1; i++) {
		if (i != N) {
			cout << setw((N-i)*2) << ' ';
		}
		cout << strings[i] << '\n';
	}

	for (int i = N-1; i >= 0; i--) {
		cout << setw((N-i)*2) << ' ' << strings[i] << '\n';
	}

	return 0;
}