// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            string nstr, mstr; getline(ss, nstr, ','); getline(ss, mstr, ',');
            int n; stringstream nss(nstr); nss >> n;
            int m; stringstream mss(mstr); mss >> m;
            if (n <= m) {
                vector<bool> sieve(m + 1, true);
                for (int i = 2; i < sieve.size(); i++) {
                    if (sieve[i]) {
                        for (int k = i + i; k < sieve.size(); k += i) {
                            sieve[k] = false;
                        }
                    }
                }
                int count = 0;
                for (int i = n; i < m + 1; i++) {
                    if (sieve[i]) count++;
                }
                cout << count << endl;
            }
        } 
    }
}
