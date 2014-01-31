// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <cmath>

using namespace std;

void read_code(string* msg, char* code) {
    int digits_in_row = 0, i = 0, idx = 2, pow = 4;
    while (digits_in_row < 3 && idx < 256 && i < msg->length()) {
        if (isdigit((*msg)[i])) digits_in_row++;
        code[idx] = (*msg)[i];
        i++; idx++;
        if (idx == pow - 1) {
            pow *= 2;
            idx += 1;            
        } 
    }
    msg->erase(0, i-3);
}

int get_token(const string& msg, int pos, int len) {
    string token = msg.substr(pos, len);
    int p = (int) pow(2.0, len-1);
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += p*(msg[pos+i]-'0');
        p /= 2;
    }
    return res;
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string msg;
    while (getline(cin, msg)) {
        char* code = new char[256]; 
        read_code(&msg, code);
        int step_size = get_token(msg, 0, 3), i = 3;
        while (step_size != 0) {
            int bp = (int) pow(2.0, step_size);
            int token = get_token(msg, i, step_size);
            i += step_size;
            while (token != bp-1) {
                cout << code[bp + token];
                token = get_token(msg, i, step_size); 
                i += step_size;
            }
            step_size = get_token(msg, i, 3);
            i += 3;
        }
        cout << endl;
        delete[] code;
    }
}
