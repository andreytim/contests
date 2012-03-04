#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	char v[6] = {'a', 'o', 'y', 'e', 'u', 'i'};
	set<char> vowels(v, v+6);
	
	string temp;
	cin >> temp;

	string res;
	for (int i = 0; i < temp.length(); i++) {
		char cur = tolower(temp[i]);
		if (vowels.count(cur) == 0) {
			res += '.';
			res += cur;
		}
	}

	cout << res;

	return 0;
}