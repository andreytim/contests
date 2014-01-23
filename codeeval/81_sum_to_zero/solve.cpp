// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <sstream>
#include <list>

using namespace std;

void print_list(const list<int> &li) {
    cout << "list: [";
    for (list<int>::const_iterator it = li.begin(); it != li.end(); it++) {
        cout << *it << ",";
    }
    cout << "]" << endl;
}

int number_of_ways(list<int> &li, list<int> &lcurr, int total, int size) {
    if (lcurr.size() == size) {
        //print_list(lcurr);
        int sum = 0;
        list<int>::const_iterator it; 
        for (it = lcurr.begin(); it != lcurr.end(); it++) 
            sum += *it;
        return (sum == total) ? 1 : 0;
    } else if (li.size() > 0) {
        int n_ways = 0;
        list<int>::iterator it;
        for (it = li.begin(); it != li.end(); it++) {
            lcurr.push_back(*it);           
            list<int> sublist(++it, li.end()); it--;
            n_ways += number_of_ways(sublist, lcurr, total, size);
            lcurr.pop_back();
        }
        return n_ways;
    }  
    return 0;
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        int n;
        stringstream ss(line);
        list<int> li, curr;
        while (ss >> n) { li.push_back(n); ss.ignore(); }
        cout << number_of_ways(li, curr, 0, 4) << endl;
    }
}

