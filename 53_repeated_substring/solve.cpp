// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct SfxIdx {
    string sfx;
    int idx;
    SfxIdx(string& s, int i):sfx(s),idx(i) {}
    bool operator< (SfxIdx other) const { return (sfx < other.sfx); }
};

string lcp(const string& str1, int start1, const string& str2, int start2) {
    int minl = min(str1.length(), str2.length());
    int non_overlap = abs(start1 - start2);
    minl = min(non_overlap, minl);
    bool only_spaces = true;
    for (int i = 0; i < minl; i++) {
        if (str1[i] != str2[i]) return (only_spaces ? "" : str1.substr(0, i));
        else if (str1[i] != ' ') only_spaces = false;
    }
    return (only_spaces ? "" : str1.substr(0, minl));
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        vector<SfxIdx> sfx_arr;
        for (int i = 0; i < line.length(); i++) {
            string temp = line.substr(i);
            sfx_arr.push_back(SfxIdx(temp, i));
        }
        sort(sfx_arr.begin(), sfx_arr.end());
        string lrs = ""; int lrs_start = 0;
        for (int i = 0; i < sfx_arr.size()-1; i++) {
            string lc_prefix = lcp(sfx_arr[i].sfx, sfx_arr[i].idx, 
                    sfx_arr[i+1].sfx, sfx_arr[i+1].idx);
            int s_start = min(sfx_arr[i].idx, sfx_arr[i+1].idx);
            if (lc_prefix.length() > lrs.length() || 
                    (lc_prefix.length() == lrs.length() && s_start < lrs_start)) {
                lrs = lc_prefix;
                lrs_start = s_start;
            }
        }        
        cout << (lrs.empty() ? "NONE" : lrs) << endl;
    }
}

