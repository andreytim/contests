#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	int n, d, t[1000];
	cin >> n >> d;
	set< pair<string, string> > friends;
	string a[1000], b[1000];

	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> t[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (a[i] == b[j] && a[j] == b[i] && t[j] > t[i] && t[j]-t[i] <= d) {
			friends.insert( pair<string, string>(min(a[i], a[j]), max(a[i], a[j])) );
		}
	}

	cout << friends.size() << endl;
	for (set< pair< string, string > > :: iterator i = friends.begin(); i != friends.end(); i++)
		cout << i->first << ' ' << i->second << endl;

	return 0;
}