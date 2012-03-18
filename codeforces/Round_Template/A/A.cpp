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

typedef unsigned long long int64;
typedef pair<int, int> pii;

template <class T>
string toString (const T& t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n;
	cin >> n;
	vector<pii> points;
	map<pii, bool> r, l, t, d;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pii p(a, b);
		if (r.find(p) == r.end()) {
			r[p] = false; l[p] = false; t[p] = false; d[p] = false;
		}

		for (int i = 0; i < points.size(); i++) {
			if (points[i].first < p.first && points[i].second == p.second) {
				l[p] = true;
				r[points[i]] = true;
			} else if (points[i].first > p.first && points[i].second == p.second) {
				r[p] = true;
				l[points[i]] = true;
			} else if (points[i].first == p.first && points[i].second < p.second) {
				d[p] = true;
				t[points[i]] = true;
			} else if (points[i].first == p.first && points[i].second > p.second) {
				t[p] = true;
				d[points[i]] = true;
			}
		}

		points.push_back(p);
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (r[points[i]] && l[points[i]] && t[points[i]] && d[points[i]]) {
			res++;
		}
	}

	cout << res;

	return 0;
}