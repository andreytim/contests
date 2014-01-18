// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

set<int> GetAllFactors(int n) {
    set<int> factors;
    factors.insert(1);
    
    // exclude all power of two first
    set<int> powers_of_2;
    int power_of_2 = 1;
    while ((n & 1) == 0) {
        power_of_2 <<= 1;
        powers_of_2.insert(power_of_2);
        factors.insert(power_of_2);
        factors.insert(n >> 1);
        n >>= 1;
    }

    // check all odd divisors less than square root
    int i = 3;
    for (; i < sqrt(n); i += 2) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n / i);
            for (set<int>::const_iterator it = powers_of_2.begin(); it != powers_of_2.end(); it++) {
                factors.insert(i * (*it));
                factors.insert((n / i) * (*it));
            }
        }
    }  

    // check perfect square
    if (i * i == n) {
        factors.insert(i);
        for (set<int>::const_iterator it = powers_of_2.begin(); it != powers_of_2.end(); it++) {
            factors.insert(i * (*it));
            factors.insert((n / i) * (*it));
        }
    }

    // check n itself
    if (factors.size() > 0) {
        factors.insert(n);
    }

    return factors;
}

int GetFactorsSum(int n) {
    int total_sum = 0;
    set<int> factors = GetAllFactors(n);
    for (set<int>::const_iterator it = factors.begin(); it != factors.end(); it++) {
        total_sum += *it;
    }
    return total_sum;
}

int main(int argc, char* argv[]) {
    int total_sum = 0;
    vector<int> sums(1, 1);    
    for (int i = 1; i < 10001; i++) {
        sums.push_back(GetFactorsSum(i));
    }
    for (int i = 1; i < 10001; i++) {
        if (sums[i] < 10000 && i != sums[i] && i == sums[sums[i]]) {
            cout << i << " " << sums[i] << endl;
            total_sum += i;
        }
    }
    cout << total_sum << endl;
}
