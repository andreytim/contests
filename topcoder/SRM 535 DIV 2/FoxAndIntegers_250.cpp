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

class FoxAndIntegers {
public:
	vector <int> get(int, int, int, int);
};

vector <int> FoxAndIntegers::get(int AminusB, int BminusC, int AplusB, int BplusC) {
	int a = 0, b = 0, c = 0;
	vector<int> res;
	if (((AminusB + AplusB)&1) == 0) {
		a = (AminusB + AplusB)/2;
		b = (AplusB - AminusB)/2;
		c = b  - BminusC;
		if (c == BplusC - b) {
			res.push_back(a);
			res.push_back(b);
			res.push_back(c);
			return res;
		}
	}
	return vector<int>();
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, vector <int> p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	FoxAndIntegers *obj;
	vector <int> answer;
	obj = new FoxAndIntegers();
	clock_t startTime = clock();
	answer = obj->get(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p4.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p4[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p4.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p4[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	vector <int> p4;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = -2;
	p2 = 3;
	p3 = 4;
	int t4[] = {2,1,3};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 0;
	p1 = 0;
	p2 = 5;
	p3 = 5;
	p4.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = -23;
	p2 = -10;
	p3 = 3;
	int t4[] = {0,-10,13};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = -27;
	p1 = 14;
	p2 = 13;
	p3 = 22;
	p4.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 30;
	p1 = 30;
	p2 = 30;
	p3 = -30;
	int t4[] = {30,0,-30};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	getchar();
	return 0;
}
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Jiro received a letter from Saburo. The letter contains four integers representing an encrypted message. Please help Jiro to decrypt the message.
// 
// You are given four ints: AminusB, BminusC, AplusB, and BplusC. Your task is to find three integers A, B, and C such that:
// 
// AminusB = A - B
// BminusC = B - C
// AplusB = A + B
// BplusC = B + C
// 
// There is always at most one triplet of integers A, B, C that satisfies all four equalities.
// 
// If it exists, return a vector <int> with exactly three elements: { A, B, C }. If there are no such integers, return an empty vector <int> instead.
// 
// 
// DEFINITION
// Class:FoxAndIntegers
// Method:get
// Parameters:int, int, int, int
// Returns:vector <int>
// Method signature:vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC)
// 
// 
// CONSTRAINTS
// -AminusB will be between -30 and 30, inclusive.
// -BminusC will be between -30 and 30, inclusive.
// -AplusB will be between -30 and 30, inclusive.
// -BplusC will be between -30 and 30. inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// -2
// 3
// 4
// 
// Returns: {2, 1, 3 }
// 
// A - B = 2 - 1 = 1
// B - C = 1 - 3 = -2
// A + B = 2 + 1 = 3
// B + C = 1 + 3 = 4
// 
// 1)
// 0
// 0
// 5
// 5
// 
// Returns: { }
// 
// A = B = C = 2.5 satisfy all four equalities, but A, B, and C must all be integers.
// 
// 2)
// 10
// -23
// -10
// 3
// 
// Returns: {0, -10, 13 }
// 
// A, B, and C may be negative or zero.
// 
// 3)
// -27
// 14
// 13
// 22
// 
// Returns: { }
// 
// 
// 
// 4)
// 30
// 30
// 30
// -30
// 
// Returns: {30, 0, -30 }
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by [KawigiEdit] 2.0!