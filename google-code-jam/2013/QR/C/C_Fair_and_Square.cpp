/*
 * =====================================================================================
 *
 *       Filename:  C_Fair_and_Square.cpp
 *
 *    Description:  Solution for Google Code Jam 2013 Qualification Round C problem.
 *                  For self training. Also experimenting with Vim tricks and plugins. :)
 *
 *        Version:  1.0
 *        Created:  15.04.2013 23:39:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrey Timoshpolsky (shpolsky), shpolsky@yandex-team.ru (shpolsky@gmail.com)
 *        Company:  Russia, Yandex
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define N 50
vector<string> numbers;

/** need to find squares  */
bool isValid(string str) {
    if (str.length() > 0 && str[0] != '0') {
        vector<int> sums(str.length()*2 - 1);
        for ( size_t i = 0; i < str.length(); ++i ) {
            for ( size_t j = 0; j < str.length(); ++j ) {
                sums[i+j] += (str[i] - '0') * (str[j] - '0');
            }
        }
        string res(sums.size(), '0');
        for ( size_t i = 0; i < sums.size(); ++i ) {
            if (sums[i] > 9) {
                return false;
            } else {
                res[i] = sums[i] + '0';
            }
        }
        numbers.push_back(res);
    }
    return str.length() < N;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  dfs
 *  Description:  Depth First Search based fair and square number generation 
 *                with root middle digit.
 * =====================================================================================
 */
void dfs(string str) {
    if (isValid(str)) {
        for ( int i = 0; i < 4 ; ++i ) {
            string s(1, i + '0');
            dfs(s + str + s);            
        }    
    }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init
 *  Description:  inits the numbers vector with the whole fair and sqare numbers less
 *                then 10**100
 * =====================================================================================
 */
void init() {
    numbers.push_back("9");
    dfs("");
    dfs("0");
    dfs("1");
    dfs("2");
/*    for (vector<string>::iterator it = numbers.begin(); 
            it != numbers.end(); ++ it) {
        cout << *it << endl;
    }*/
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  cmp
 *  Description:  compares two big numbers in string format 
 * =====================================================================================
 */
bool cmp(const string& a, const string& b) {
    if (a.length() < b.length()) {
        return true;
    } else if (a.length() > b.length()) {
        return false;
    }
    return a <= b;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solve
 *  Description:  Generating all possible numbers consist of {0,1,2,3} 
 *                between sqrt(A) and sqrt(B) such that sum of their digit squares
 *                is less then 10.
 * =====================================================================================
 */
void solve() {
    string A, B;
    cin >> A >> B;
    int count = 0;
    for ( vector<string>::iterator it = numbers.begin();
            it != numbers.end(); ++it ) {
        if (cmp(A, *it) && cmp(*it, B)) {
            count++;
        }
    }
    cout << count;
}

int main( int argc, char *argv[] ) {
    init();
//    cout << numbers.size() << endl;
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}
