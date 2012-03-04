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

string toString(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

string getTer(long a) {
	string res = "";
	while (a != 0) {
		int rem = a%3;
		res = toString(rem) + res;
		a = (a-rem)/3;
	}
	return res;
}

char getDiff(char ac, char bc) {
	int a = ac - '0', b = bc - '0';
	int res = a-b;
	if (res < 0) {
		res = 3+res;
	}
	return '0' + res;
}

void generateTest() {
	cout << 14 << '\n' << 34;
}

int main() {
	//freopen("input.txt", "wt", stdout);
	//generateTest();
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	long a,c;
	cin >> a >> c;

	string tera = getTer(a);
	string terc = getTer(c);
	int diffL = terc.length() - tera.length();
	stringstream ss;
	if (diffL > 0) {
		stringstream ss;	
		ss << setfill('0') << setw(diffL + tera.length()) << tera;
		tera = ss.str();
	} else if (diffL < 0) {
		ss << setfill('0') << setw(-diffL + terc.length()) << terc;
		terc = ss.str();
	}

	string strRes = "";
	for (int i = 0; i < terc.length(); i++) {
		strRes += getDiff(terc[i], tera[i]);
	}

	int res = 0;
	int mult = 1;
	for (int i = strRes.length()-1; i > -1; i--) {
		res += (strRes[i] - '0')*mult;
		mult *= 3;
	}

	cout << res;

	return 0;
}