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

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	string str1, str2;
	cin >> str1 >> str2;
	
	int res = 0;
	for(int i = 0; i < str1.length(); i++) {
		char c1 = tolower(str1[i]), c2 = tolower(str2[i]);
		if (c1 > c2) {
			res = 1;
			break;
		} else if (c1 < c2) {
			res = -1;
			break;
		}
	}
	
	cout << res;

	return 0;
}