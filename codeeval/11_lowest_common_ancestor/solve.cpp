// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class BST {
    
    private:
        
        struct Node {
            int value;
            Node *left;
            Node *right;
            Node(int v):value(v) {}
        };
        
        Node *root;

    public:
        
        BST() { add(30); add(8); add(52); add(3); add(20); add(10); add(29); }

        void add(int value) {
            if (!root) {
                root = new Node(value);
            } else {
                Node *curr = root;
                Node *parent;
                while (curr) {
                    parent = curr;
                    if (curr->value > value)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                if (parent->value > value) {
                    parent->left = new Node(value);
                } else {
                    parent->right = new Node(value);
                }
            }
        }

        int common_ancestor(int v1, int v2) {
            Node *curr = root;
            while ((curr->value > v1 && curr->value > v2) ||
                   (curr->value < v1 && curr->value < v2)) {
                if (curr->value > v1) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            return curr->value;
        }
};

int main(int argc, char *argv[]) {
    BST tree;
    std::ifstream f(argv[1]);
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            std::stringstream ss(line);
            int v1, v2;
            ss >> v1 >> v2;
            std::cout << tree.common_ancestor(v1, v2) << std::endl;
        }
    }    
}

