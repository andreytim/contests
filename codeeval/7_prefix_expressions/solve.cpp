// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

enum Ops { PLUS = '+', MUL = '*', DIV = '/', MINUS = '-' };

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        stack<string> tokens;
        string token; stringstream ss(line);
        while (getline(ss, token, ' ')) tokens.push(token);
        stack<double> nums;
        while (!tokens.empty()) {
            string curr_token = tokens.top(); tokens.pop();
            if (curr_token == "/" || curr_token == "*" || 
                    curr_token == "+" || curr_token == "-") {
                Ops op = Ops(curr_token[0]);
                double l = nums.top(); nums.pop();
                double r = nums.top(); nums.pop();
                switch (op) {
                    case PLUS: nums.push(l + r); break;
                    case MUL: nums.push(l * r); break;
                    case DIV: nums.push(l / r); break;
                    case MINUS: nums.push(l - r); break;          
                }
            } else {
                double n; stringstream nstr(curr_token); nstr >> n;
                //cout << curr_token << "-" << n << ";";
                nums.push(n);
            }
        }
        cout << nums.top() << endl;
    }
}
