//
// Created by Me on 2025-01-11.
//
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <stack>
#include <iostream>

class Node {
public:

    static Node* mergeTrees(Node* root1, Node* root2);
    Node();

    Node(const int value) {
        level = 0;
        children.clear();
        this->value = value;
    }
    static void printTree(Node* root);
    std::vector<Node*> children;
    int value;
    int level;
};

#endif //NODE_H
