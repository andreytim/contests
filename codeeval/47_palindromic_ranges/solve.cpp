// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>

using namespace std;

bool is_palindrome(int n) {
    int nr = 0, nl = n;
    while (nl > 0) {
        nr = 10 * nr + nl % 10;
        nl /= 10;
    }
    return nr == n;
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    int L = 0, R = 0;
    while (cin >> L) {
        cin >> R;
        int total = 0;
        for (int i = L; i <= R; i++) {
            for (int j = i; j <= R; j++) {
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (is_palindrome(k)) count++;
                }
                if ((count & 1) == 0) total++;
            }
        }
        cout << total << endl;
    } 
}

