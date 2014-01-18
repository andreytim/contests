// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

string IntToString(int n) { ostringstream oss; oss << n; return oss.str(); }

string AddBigNumbers(string &a, string &b) {
    int carry = 0;
    string result = "";
    int m = max(a.length(), b.length());
    for (int i = 1; i <= m; i++) {
        int ac = (i <= a.length()) ? a[a.length() - i] - '0' : 0;
        int bc = (i <= b.length()) ? b[b.length() - i] - '0' : 0;
        int cnext = ac + bc + carry;
        carry = cnext > 9 ? 1 : 0;
        cnext %= 10;
        result = IntToString(cnext) + result;
    }
    if (carry == 1) result = "1" + result;
    return result;
}

int main() {
    string x = "1", y = "1";
    long long n = 2;
    while (y.length() < 1000) {
        string f = AddBigNumbers(x, y);
        x = y; y = f; n++;
    }
    cout << n << endl;
}
