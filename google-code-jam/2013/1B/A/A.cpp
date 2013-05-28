/*
 * =====================================================================================
 *
 *       Filename:  A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.05.2013 19:53:00
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
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long A;
    int N, a;
    cin >> A >> N;
    vector<int> motes;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        motes.push_back(a);
    }
    if (A == 1) {
        cout << motes.size();
        return;
    }
    sort(motes.begin(), motes.end());
    int t = 0, tc = 0, tk = 0;
    long long AC = 0;
    for (int i = 0; i < N; ++i) {
        if (motes[i] < A + AC) {
            A += AC + motes[i];
            t += tc;
            AC = 0;
            tc = 0;
            tk = 0;
        } else if (motes[i] >= A + AC && motes[i] < 2 * (A + AC) - 1) {
            t += tc + 1;
            A += A + 2 * AC - 1 + motes[i];
            AC = 0;
            tc = 0;
            tk = 0;
        } else if (motes[i] >= 2 * (A + AC) - 1) {
            while (motes[i] >= A + AC) {
                AC += A + AC - 1;
                tc += 1;
            }
            AC += motes[i];
            tk += 1;
        }
    }
    cout << t + (tc > tk ? tk : tc);
}

int main( int argc, char *argv[] ) {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}
