// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 1; i < 13; i++) {
        cout << i;
        for (int j = 2; j < 13; j++) {
            cout << fixed << setw(4) << i*j; 
        }
        cout << endl;
    }
}
