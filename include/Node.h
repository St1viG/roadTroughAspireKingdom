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

    static Node* mergeTrees(Node* root1, Node* root2, bool isMax = true);
    Node();

    Node(const int value) {
        this->value = value;
    }
    static void printTree(Node* root);

    void switchTree(bool isMax);

    void freeTree();


    std::vector<Node*> children;
    Node* parent = nullptr;
    int value;
    int level = 0;
};

#endif //NODE_H
