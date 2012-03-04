#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string reverse_case(string &str) {
	for(int i = 0; i < str.length(); i++) {
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		} else {
			str[i] = toupper(str[i]);
		}
	}
	return str;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	string word;
	cin >> word;
	int i;
	for(i = 1; i < word.length(); i++) {
		if (islower(word[i])) {
			break;
		}
	}
	if (i != word.length()) {
		cout << word;
	} else {
		cout << reverse_case(word);
	}

	return 0;
}