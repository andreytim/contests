// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "rt", stdin);
    int total;
    while (std::cin >> total) {
        std::cout << total / 5 + total % 5 / 3 + total % 5 % 3 << std::endl;
    }
}

