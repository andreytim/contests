// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

enum Token {
    NUMBER, END, 
    L_PAR='(', R_PAR=')', 
    PLUS='+', MINUS='-',
    MUL='*', DIV='/', 
    POW='^'
};

Token curr_token;
double curr_value;

Token read_token(std::stringstream *ss) {
    char next_ch = 0;
    (*ss) >> next_ch;
    while (next_ch == ' ') (*ss) >> next_ch;
    if (next_ch >= '0' && next_ch <= '9') {
        (*ss).putback(next_ch); 
        (*ss) >> curr_value;
        return curr_token = NUMBER;
    } else if (next_ch == 0) return curr_token = END; 
    else return curr_token = Token(next_ch);
}

double expr(std::stringstream *ss, bool need_read);

double term(std::stringstream *ss, bool need_read) {
    if (need_read) read_token(ss);
    double d = curr_value;
    switch (curr_token) {
        case NUMBER:
            read_token(ss);
            return d;
        case L_PAR:
            d = expr(ss, true);
            read_token(ss);
            return d;
        case MINUS:
            return -term(ss, true);
        default:
            throw std::runtime_error("Wrong term!");
    }
}

double pow(std::stringstream *ss, bool need_read) {
    double left = term(ss, need_read);
    while (true) {
        if (curr_token == POW) {
            left = std::pow(left, term(ss, true)); 
        } else return left;
    }
}

double muldiv(std::stringstream *ss, bool need_read) {
    double left = pow(ss, need_read);
    while (true) {
        switch (curr_token) {
            case MUL:
                left *= pow(ss, true);
                break;
            case DIV:
                left /= pow(ss, true);
                break;
            default:
                return left;
        }
    }
}

double expr(std::stringstream *ss, bool need_read) {
    double left = muldiv(ss, need_read);
    //std::cout << curr_token;
    while (true) {
        switch (curr_token) {
            case PLUS:
                //std::cout << "+ " << left; 
                left += muldiv(ss, true);
                //std::cout << "; res = " << left;
                break;
            case MINUS:
                left -= muldiv(ss, true);
                break;
            default:
                return left;
        }
    }
}

void eval(const std::string &line) {
    std::stringstream ss(line);
    double res = expr(&ss, true);
    if (res - (int)res == 0) std::cout << res << std::endl;
    else {
        std::stringstream iss;
        iss << std::fixed << std::setprecision(5) << res;
        std::string resstr = iss.str();
        int i = resstr.length() - 1;
        while (resstr[i] == '0') i--;
        if (i < resstr.length() - 1)
            resstr.erase(resstr.begin() + i + 1, resstr.end());
        std::cout << resstr << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "rt", stdin);
    std::string line;
    while (std::getline(std::cin, line)) {
        eval(line);
    }
}

