// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

void PrintM(const vector< vector<int> >& dpm) {
  for (int i = 0; i < dpm.size(); i++) {
    for (int j = 0; j < dpm[i].size(); j++) {
      cout << (dpm[i][j] ? '1' : '0');
    }
    cout << endl;
  }
}

bool CheckPossibility(const string& binary, const string& letters) {
  if (binary.length() > letters.length() ||
      (binary[0] == '0' && letters[0] == 'B')) {
    return false;
  }
  vector< vector<int> > dpm(binary.length(), vector<int>(letters.length(), false));
  dpm[0][0] = true;
  int k = 1;
  while (k < letters.length() && letters[k] == letters[0]) {
    dpm[0][k] = true;
    k++;
  }
  for (int i = 1; i < binary.length(); i++) {
    for (int j = i; j < letters.length(); j++) {
      if ((dpm[i-1][j-1] && (letters[j] == 'A' || binary[i] == '1')) ||
          (dpm[i][j-1] && (letters[j] == letters[j-1]))) {
        dpm[i][j] = true;  
      } else {
        dpm[i][j] = false;
      }
    }
  }
  // PrintM(dpm);
  return dpm[binary.length() - 1][letters.length() - 1];
}

int main(int argc, char* argv[]) {
  freopen(argv[1], "rt", stdin);
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    string binary; string letters;
    getline(ss, binary, ' '); getline(ss, letters, ' ');
    cout << (CheckPossibility(binary, letters) ? "Yes" : "No") << endl;
  }
}

