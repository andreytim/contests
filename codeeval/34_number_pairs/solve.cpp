// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int n, int lo, int hi) {
    // cout << "-- n=" << n << "; lo=" << lo << "; hi=" << hi << "; "; 
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (v[mid] > n) {
            hi = mid - 1;
        } else if (v[mid] < n) {
            lo = mid + 1;
        } else {
            // cout << "mid=" << mid << "; ";
            return mid;
        }
    }
    // cout << "not found; ";
    return lo;
}

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            string vstr, sumstr, item;
            getline(ss, vstr, ';'); getline(ss, sumstr, ';');
            vector<int> v;
            stringstream vss(vstr); 
            while (getline(vss, item, ',')) {
                stringstream iss(item);
                int el; iss >> el; v.push_back(el);
            }
            int sumv; stringstream nss(sumstr); nss >> sumv;
            int pairs_count = 0;
            if (v.size() > 1) {
                int i = 0;
                while (i < v.size() - 1 && v[i] <= sumv) {
                    int other = sumv - v[i];
                    if (v[binary_search(v, other, i + 1, v.size() - 1)] == other) {
                        if (pairs_count > 0) cout << ";";
                        cout << v[i] << "," << other;
                        pairs_count++;
                    }
                    i++;    
                }
            }
            if (pairs_count == 0) cout << "NULL";
            cout << endl;
        }
    }
}

