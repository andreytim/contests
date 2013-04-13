#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int N = 4;

// just bruteforce
void solve() {
    string line;
    char board[N][N];
    
    // read
    getline(cin, line); 
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        for (int j = 0; j < N; ++j) {
            board[i][j] = line[j];
        }
    }

    // check
    string pls = "XO";
    bool completed = true;
    for (int i = 0; i < pls.length(); ++i) {
        bool vert[N];
        fill_n(vert, N, true);
        bool diag[2] = {true, true};
        for (int pi = 0; pi < N; ++pi) {
            bool curr = true;
            for (int pj = 0; pj < N; ++pj) {
                if (board[pi][pj] != pls[i] && board[pi][pj] != 'T') {
                    if (board[pi][pj] == '.') completed = false;
                    curr = false;
                    vert[pj] = false;
                    if (pi == pj) diag[0] = false;
                    if (pi == N - pj - 1) diag[1] = false;
                }
            }
            if (curr) { 
                cout << pls[i] << " won";
                return;
            }
        }
        if (diag[0] || diag[1]) {
            cout << pls[i] << " won";
            return;
        }
        for (int k = 0; k < N; ++k) {
            if (vert[k]) {
                cout << pls[i] << " won";
                return;
            }
        }
    }

    if (completed) {
        cout << "Draw";
    } else {
        cout << "Game has not completed";
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}
