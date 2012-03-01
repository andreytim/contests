#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector< pair<int, int> > vii;
typedef vector< vector<int> > mi;
typedef vector<char> vc;
typedef vector< vector<char> > mc;

#define fors(i, n) for(int i = 0; i < n; i++)
#define trvec(i, vec) for(int i = 0; i < vec.size(); i++)

enum direction { UP, DOWN, LEFT, RIGHT };

int getPig(const ii& point, const mc& field, direction dir) {
	int m = field[0].size();
	switch (dir) {
		case UP:
			if (point.first > 0 && field[point.first-1][point.second] == 'P') {
				return (point.first-1)*m + point.second;
			}
			break;
		case DOWN:
			if (point.first < field.size()-1 && field[point.first+1][point.second] == 'P') {
				return (point.first+1)*m + point.second;
			}
			break;
		case LEFT:
			if (point.second > 0 && field[point.first][point.second-1] == 'P') {
				return (point.first)*m + point.second - 1;
			}
			break;
		case RIGHT:
			if (point.second < field[point.first].size()-1 && field[point.first][point.second+1] == 'P') {
				return (point.first)*m + point.second + 1;
			}
			break;
	}
	return -1;
}

int main_PandW_116B() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	cin >> n >> m;

	vii wolves;
	mc field(n, vc(m, '.'));
	map<int, int> pigs2state;

	trvec(i, field) {
		trvec(j, field[i]) {
			cin >> field[i][j];
			if (field[i][j] == 'W') {
				wolves.push_back(ii(i,j));
			} else if (field[i][j] == 'P') {
				pigs2state[i*m + j] = 1;
			}
		}
	}

	map<ii, vi> wolves2pigs;
	trvec(i, wolves) {
		vi pigs;
		int pig = getPig(wolves[i], field, UP);
		if (pig > -1) {
			pigs.push_back(pig);
		}
		pig = getPig(wolves[i], field, DOWN);
		if (pig > -1) {
			pigs.push_back(pig);
		}
		pig = getPig(wolves[i], field, LEFT);
		if (pig > -1) {
			pigs.push_back(pig);
		}
		pig = getPig(wolves[i], field, RIGHT);
		if (pig > -1) {
			pigs.push_back(pig);
		}
		wolves2pigs[wolves[i]] = pigs;
	}

	vii currWolves;
	int numPigs = 0;
	int res = 0;
	while (numPigs != 4)
	{
		currWolves.clear();
		numPigs++;
		
		trvec(i,wolves) {
			if (wolves2pigs[wolves[i]].size() == numPigs) {
				currWolves.push_back(wolves[i]);
			}
		}

		trvec(i,currWolves) {
			trvec(j, wolves2pigs[currWolves[i]]) {
				if (pigs2state[wolves2pigs[currWolves[i]][j]] == 1) {
					pigs2state[wolves2pigs[currWolves[i]][j]] = 0;
					res++;
					break;
				}
			}
		}
	}

	cout << res;

	return 0;
}