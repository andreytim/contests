#include <stdio.h>
#include <iostream>
#include <cmath>
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

int main_Strings_71A() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int N;
	scanf("%d", &N);
	vector<string> strings(N);
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		int length = temp.length();
		if (length < 11) {
			strings[i] = temp;
		} else {
			strings[i] = temp[0] + toString(length-2) + temp[length-1];
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << strings[i] << "\n";
	}

	return 0;
}