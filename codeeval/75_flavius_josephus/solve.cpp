// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int v, Node *n = 0):value(v),next(n) {}
};

Node *add(Node *tail, int value) {
    tail->next = new Node(value);
    return tail->next;
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        int n, m; stringstream ss(line);
        ss >> n; ss.ignore(1); ss >> m;
        Node *head = new Node(0);
        Node *tail = head;
        for (int i = 1; i < n; i++) { tail = add(tail, i); }
        tail->next = head;
        Node *prev = tail;  
        Node *curr = head;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m-1; j++) { 
                tail = curr;
                curr = curr->next; 
            }
            cout << curr->value << " ";
            tail->next = curr->next;
            curr = curr->next;
        }     
        cout << endl;
    }
}

