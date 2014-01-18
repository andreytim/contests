// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class str_comparator {
    public:
        bool operator() (const string& lhs, const string& rhs) const {
            return lhs.length() < rhs.length();
        }
};

int main(int argc, char* argv[]) {
    ifstream inf(argv[1]);
    if (inf.is_open()) {
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(inf.rdbuf());
        int N;
        cin >> N;
        string line;
        priority_queue<string, vector<string>, str_comparator> topn;
        while (getline(cin, line)) {
            if (!line.empty()) {
                topn.push(line);
            }
        }
        for (int i = 0; i < N; i++) {
            cout << topn.top() << endl;
            topn.pop();
        }
    }
}
