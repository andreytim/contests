// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string lstr, kstr; getline(ss, lstr, ';'); getline(ss, kstr, ';');
        int k; stringstream kss(kstr); kss >> k;
        string es; stringstream lss(lstr);
        int i = 0, total = 0;
        stack<string> st;
        while (getline(lss, es, ',')) {
            st.push(es);
            if (++i == k) {
                while (!st.empty()) {
                    if (total++ > 0) cout << ",";
                    cout << st.top(); st.pop();
                }  
                i = 0;
            }
        }
        string tail;
        while (!st.empty()) { 
            if (st.size() > 1 || total > 0) tail = "," + st.top() + tail;
            else tail = st.top() + tail;
            st.pop();
        }
        cout << tail << endl;
    }
}

