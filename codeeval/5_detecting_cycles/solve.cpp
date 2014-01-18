// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    std::ifstream f(argv[1]);
    if (f.is_open()) {
        std::string line;
        while (getline(f, line)) {
            std::stringstream ss(line);
            int f[100];
            std::fill(f, f+100, -1);
            int prev = -1, n = -1;
            vector<int> v;
            ss >> prev;
            while (ss >> n) {
                if (f[prev] == -1) {
                    v.push_back(prev);
                    f[prev] = n;
                    prev = n;
                } else if (f[prev] != n) {
                    v.push_back(prev);
                    prev = n;
                } else {
                    break;
                }
            }
            int x = prev;
            int i = 0;
            while (v[i] != prev) i++;
            for (int j = i; j < v.size(); j++) cout << v[j] << " ";
            std::cout << std::endl;
        }
    }
}

