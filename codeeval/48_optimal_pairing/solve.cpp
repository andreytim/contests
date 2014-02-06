// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isvowel(char ch) {
    return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || 
        ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || 
        ch == 'u' || ch == 'U' || ch == 'y' || ch == 'Y';
}

bool isletter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool have_common_factor(int a, int b) {
    for (int i = 2; i*i <= a && i*i <= b; i++) {
        if (a % i == 0 && b % i == 0) return true;
    }
    return b % a == 0 || a % b == 0;
}

double suit_score(const string& product, const string& customer) {
    int pr_lc = 0, cs_lc = 0, cs_vc = 0;
    for (int i = 0; i < product.length(); i++) 
        if (isletter(product[i])) pr_lc++;
    for (int i = 0; i < customer.length(); i++) {
        if (isletter(customer[i])) {
            cs_lc++;
            if (isvowel(customer[i])) cs_vc++;
        }
    }
    cout << "pr_lc=" << pr_lc << "; cs_lc=" << cs_lc << "; cs_vc=" << cs_vc << "; ";
    double score = ((pr_lc & 1) == 0) ? cs_vc * 1.5 : cs_lc - cs_vc;
    return have_common_factor(pr_lc, cs_lc) ? score * 1.5 : score;
}

struct Node {
    int idx;
    string name;
    Node(int i, string& n):idx(i),name(n) {}
};

double max_total_score(const vector<string>& products, const vector<string>& customers) {
    double scores[products.size()][customers.size()];
    double max_score = 0.0;
    for (int i = 0; i < products.size(); i++) {
        for (int j = 0; j < customers.size(); j++) {
            double score = suit_score(products[i], customers[j]);
            cout << "[" << products[i] << "] -> [" << customers[j] << "] = " << score << endl;
            scores[i][j] = score;
            max_score = max(max_score, score)
        }
    }
    for (int i = 0; i < products.size(); i++)
        for (int j = 0; j < customers.size(); j++) scores[i][j] = max_score - scores[i][j];
    return 0.0;
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        int delim_pos = line.find(';');
        stringstream ssc(line.substr(0, delim_pos));
        stringstream ssp(line.substr(delim_pos + 1));
        vector<string> customers, products;
        string token;
        while (getline(ssc, token, ',')) customers.push_back(token);
        while (getline(ssp, token, ',')) products.push_back(token);
        cout << max_total_score(products, customers) << endl;
    }
}

