#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int N;
	cin >> N;
	int max = 0, curr = 0;
	for (int i = 0; i < N; i++) {
		int in, out;
		cin >> out >> in;
		curr -= out;
		curr += in;
		if (curr > max)
			max = curr;
	}

	cout << max;

	return 0;
}