#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int getDiffCount(const string &str1, const string &str2, int length) {
	int res = 0;
	for (int i = 0; i < length; i++) {
		if (str1[i] != str2[i]) {
			res++;
		}
	}
	if (length == 1) {
		return res;
	} else {
		int subDiff1 = getDiffCount(str1.substr(0, length-1), str2, length-1) + 1;
		int subDiff2 = getDiffCount(str1.substr(1, length), str2, length-1) + 1;
		if (subDiff1 < res) {
			res = subDiff1;
		}
		if (subDiff2 < res) {
			res = subDiff2;
		}
		return res;
	}
	
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	string str1, str2;
	cin >> str1 >> str2;
	int length1 = str1.length();
	int length2 = str2.length();

	if (length1 > length2) {
		swap(str1, str2);
		swap(length1, length2);
	}

	int minDiff = getDiffCount(str1, str2, length1);

	cout << minDiff;

	return 0;
}