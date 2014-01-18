// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

void init_map(map<int, string> &m) {
    m[1] = "PENNY";
    m[5] = "NICKEL";
    m[10] = "DIME";
    m[25] = "QUARTER";
    m[50] = "HALF DOLLAR";
    m[100] = "ONE";
    m[200] = "TWO";
    m[500] = "FIVE";
    m[1000] = "TEN";
    m[2000] = "TWENTY";
    m[5000] = "FIFTY";
    m[10000] = "ONE HUNDRED";
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        map<int, string> cr_map;
        init_map(cr_map); 
        while (getline(f, line)) {
            stringstream ss(line);
            string pstr, cstr; getline(ss, pstr, ';'); getline(ss, cstr, ';');
            float ppf; stringstream pss(pstr); pss >> ppf;
            float chf; stringstream css(cstr); css >> chf;
            int pp = round(ppf * 100);
            int ch = round(chf * 100);
            if (pp > ch) {
                cout << "ERROR";
            } else if (pp == ch) {
                cout << "ZERO";
            } else {
                int change = ch - pp, count = 0;
                map<int, string>::reverse_iterator rit;
                for (rit = cr_map.rbegin(); rit != cr_map.rend(); rit++) {
                    if (rit->first <= change) {
                        int times = change / rit->first;
                        for (int i = 0; i < times; i++) {
                            if (count++ > 0) cout << ",";
                            cout << rit->second;
                        }
                        change %= rit->first;
                    }
                }
            }
            cout << endl;
        }
    }
}
