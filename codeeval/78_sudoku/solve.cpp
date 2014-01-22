// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

class bitset {    
    private:
        int bits;
    public:
        bitset() { bits = 0; }
        void add(int digit) {
            bits |= (1 << digit);
        }
        bool contains(int digit) {
            return (bits & (1 << digit)) != 0;
        }
        void remove(int digit) {
            if (contains(digit)) bits ^= (1 << digit);
        }
};

bool check_rows_and_cols(const vector<int> &board, int board_size, int size) {
    for (int i = 0; i < board_size; i++) {
        bitset row;
        bitset col;
        for (int j = 0; j < board_size; j++) {
            int rowidx = board_size*i + j;
            int colidx = i + board_size*j;
            //cout << i << ":" << rowidx << "," << colidx << ";";
            if (row.contains(board[rowidx]) || col.contains(board[colidx])) {
                return false;
            }
            row.add(board[rowidx]);
            col.add(board[colidx]);
        }
    }
    return true;
}

bool check_squares(const vector<int> &board, int board_size, int size) {
    for (int i = 0; i < board_size*board_size; i += size) {
        if ((i + 1)/ board_size % size == 0) {
            bitset square;
            for (int a = 0; a < size; a++) {
                for (int b = 0; b < size; b++) {
                    int idx = i + a*board_size + b;
                    if (square.contains(board[idx])) {
                        return false;            
                    } else square.add(board[idx]);
                    //cout << board[idx];
                }
                //cout << endl;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (cin >> line) {
        stringstream ss(line);
        int size; string ssize; getline(ss, ssize, ';'); stringstream sss(ssize); sss >> size;
        string sboard; getline(ss, sboard, ';');
        stringstream ssb(sboard);
        string sdigit;
        vector<int> board;
        while (getline(ssb, sdigit, ',')) {
            board.push_back(sdigit[0] - '0');
        }
        if (check_rows_and_cols(board, size, sqrt(size)) 
                && check_squares(board, size, sqrt(size))) {
            cout << "True" << endl;
        } else cout << "False" << endl;
    }
}
