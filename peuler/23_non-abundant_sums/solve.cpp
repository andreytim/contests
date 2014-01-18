// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <vector>
#include <iostream>

using namespace std;

const int BORDER = 28123;

class Primes {
    
    private:
        int current_idx;
        vector<int> primes;
    
    public:
        Primes() {
            current_idx = 0;
            vector<bool> sieve(BORDER, true);
            for (int i = 2; i < BORDER; i++) {
                if (sieve[i]) {
                    primes.push_back(i);
                    for (int k = i; k < BORDER; k += i) {
                        sieve[k] = false;
                    }
                }
            }
        }

        int next() {
            if (current_idx == primes.size()) reset();
            return primes[current_idx++];
        }

        void reset() {
            current_idx = 0;
        }
};

int GetProperDivisorsSum(int n, Primes *primes) {
    int sum = 1, dump = n;
    primes->reset();
    while (n > 1) {
        int p = primes->next();
        if (n % p == 0) {
            int pow = p*p;
            n /= p;
            while (n % p == 0) {
                n /= p;
                pow *= p;
            }
            sum = sum * (pow - 1);
            sum = sum / (p - 1);
            //cout << p << '^' << pow << ' ';
        }
    }
    //cout << endl;
    return sum - dump;
}

int main() {
    Primes *primes = new Primes();
    primes->next();
    vector<bool> cant(BORDER, true);
    vector<int> abundants;
    for (int i = 1; i < BORDER; i++) {
        if (GetProperDivisorsSum(i, primes) > i) {
            abundants.push_back(i);
            for (int k = 0; k < abundants.size(); k++) {
                if (abundants[k] + i < BORDER) {
                    cant[abundants[k] + i] = false;
                }
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < BORDER; i++) {
        if (cant[i]) {
            sum += i;
            cout << i << endl;
        }
    }
    delete primes;
    cout << sum << endl;
}

