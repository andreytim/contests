// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>

int main() {
    union {
        int n;
        char bytes[4];
    } e = { 0x01020304 };
    std::cout << (e.bytes[0] == 1 ? "BigEndian" : "LittleEndian") << std::endl;
}

