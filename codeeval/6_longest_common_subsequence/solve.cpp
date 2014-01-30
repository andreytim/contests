// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector< vector<int> > lcs_search(const string& seq1, const string& seq2) {
    vector< vector<int> > t(seq1.length() + 1, vector<int>(seq2.length() + 1, 0));
    for (int i = 1; i <= seq1.length(); i++) {
        for (int j = 1; j <= seq2.length(); j++) {
            if (seq1[i-1] == seq2[j-1]) {
                t[i][j] = t[i-1][j-1] + 1;
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t;
}

string backtrack(const vector< vector<int> >& t, const string& seq1, const string& seq2, int i, int j) {
    if (i == 0 || j == 0) return "";
    else if (seq1[i-1] == seq2[j-1]) return backtrack(t, seq1, seq2, i-1, j-1) + seq1[i-1];
    else if (t[i][j-1] > t[i-1][j]) return backtrack(t, seq1, seq2, i, j-1);
    return backtrack(t, seq1, seq2, i-1, j);
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            string seq1, seq2; getline(ss, seq1, ';'); getline(ss, seq2, ';');
            vector< vector<int> > t = lcs_search(seq1, seq2);
            cout << backtrack(t, seq1, seq2, seq1.length(), seq2.length()) << endl;
        }
    }
}

