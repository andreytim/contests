// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

template <class T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>(T v, Node<T>* n):value(v),next(n) {}
};

class stack {
    private:
        Node<int>* top;
    public:
        int pop() {
            if (!empty()) {
                Node<int>* old_top = top;
                top = top->next;
                return old_top->value;
            }
            throw std::runtime_error("There's nothing to pop from the stack!");
        }

        void push(int value) {
            top = new Node<int>(value, top);
        }

        bool empty() {
            return top == 0;
        }
};

int main(int argc, char* argv[]) {
    std::ifstream f(argv[1]);
    if (f.is_open()) {
        std::string line;
        stack st;
        while (std::getline(f,line)) {
            std::stringstream ss(line);
            int num;
            while (ss >> num) {
                st.push(num);
            }
            int i = 0;
            while (!st.empty()) {
                if ((i & 1) == 0) {
                    std::cout << st.pop() << " ";
                } else {
                    st.pop();
                }
                i++;
            }
            std::cout << std::endl;
        }
        f.close();
    }
}
