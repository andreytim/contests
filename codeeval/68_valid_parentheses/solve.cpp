// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class stack {
    private:
        struct Node {
            char value;
            Node *next;
            Node(char v, Node *n = 0):value(v),next(n) {}
        };
        Node* top;
    public:
        stack() { top = 0; }
        ~stack() { 
            while (top != 0) {
                Node *old = top;
                top = top->next; 
                delete old; 
            }
        }
        
        char pop() {
            if (!empty()) {
                char ch = top->value;
                top = top->next;
                return ch;
            }
            return '_';
        }

        char peek() {
            if (!empty()) {
                return top->value;
            }
            return '_';
        }

        void push(char val) {
            top = new Node(val, top);
        }

        bool empty() { return top == 0; }
};

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        stack tracker;
        int i;
        for (i = 0; i < line.length(); i++) {
            char ch = line[i];
            if ((ch == '(') || (ch == '{') || (ch == '[')) {
                tracker.push(ch);
            } else if (((ch == ')') && (tracker.peek() == '(')) ||
                    ((ch == ']') && (tracker.peek() == '[')) ||
                    ((ch == '}') && (tracker.peek() == '{'))) {
                tracker.pop();
            } else break;
        }
        if (tracker.empty() && i == line.length()) cout << "True" << endl;
        else cout << "False" << endl;
    }
}
