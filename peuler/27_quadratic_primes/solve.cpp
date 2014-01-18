// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <ext/hash_set>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

const hash_set<int> GeneratePrimes(int lim) {
    vector<bool> sieve(lim, true);
    hash_set<int> primes;
    for (int i = 2; i < lim; i++) {
        if (sieve[i]) {
            primes.insert(i);
            for (int k = i; k < lim; k += i) {
                sieve[k] = false;
            }
        }
    }
    return primes;
}
const hash_set<int> primes = GeneratePrimes(1024*1024*2);

int GetCount(int a, int b) {
    int qres = a + b + 1, n = 1;
    while (primes.find(qres) != primes.end()) {
        n += 1;
        qres = n*n + n*a + b;
    }
    return n;
}

int main() {
    int maxcount = 0, maxprod = 0;
    for (int i = -999; i < 1000; i++) {
        for (int j = 3; j < 1000; j += 2) {
            int c = GetCount(i, j);
            if (c > maxcount) {
                maxcount = c;
                maxprod = i * j;
            }
        }
    }
    cout << maxprod << endl;
}

