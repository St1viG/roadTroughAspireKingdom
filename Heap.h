//
// Created by Stevan on 2025-01-10.
//

#include <iostream>
#include <vector>

#ifndef HEAP_H
#define HEAP_H


class Node {
public:

    static Node* mergeTrees(Node* root1, Node* root2);
    Node();

    Node(const int value) {
        level = 0;
        parent = nullptr;
        children.clear();
        this->value = value;
    }
    static void printTree(Node* root);

    Node* parent;
    std::vector<Node*> children;
    int value;
    int level;
};



class Heap {
public:
    //hi
    void insert(int value);

    void remove(int value);

    int find(int value);

    void mergeHeap(Heap* heap2);

    Heap(){};

    Heap(Node* root);

    void printHeap();

private:
    std::vector<Node*> roots;




};
#endif //HEAP_H
