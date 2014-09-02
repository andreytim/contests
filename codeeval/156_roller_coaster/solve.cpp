// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
  freopen(argv[1], "rt", stdin);
  char c;
  bool upper = true;
  while (cin.get(c)) {
    if (c >= 'a' && c <= 'z') {
      if (upper) {
        c = c - 'a' + 'A';
      }
      upper = !upper;
    } else if (c >= 'A' && c <= 'Z') {
      if (!upper) {
        c = c - 'A' + 'a';
      }
      upper = !upper;
    } else if (c == '\n') {
      upper = true;
    }
    cout << c;
  }
}

