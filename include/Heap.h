//
// Created by Me on 2025-01-10.
//
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stack>

#include "Node.h"

class Heap {
public:
    int numberOfNodes = 0;

    Heap(bool isMax = true) {
        this->isMax = isMax;
        this->roots.push_back(nullptr);
    }

    Heap(Node* root, bool isMax = true) {
        this->isMax = isMax;
        if (root!=nullptr)
            roots.push_back(root);
    };

    ~Heap() {
        this->roots.clear();
        this->extreme = nullptr;
    }

    void insert(int value);

    void insertNode(Node* node);

    void clear();

    void remove();

    void mergeHeap(Heap* heap2);

    void printHeap();
std::vector<Node*> roots;
private:
    bool isMax = true;
    Node* extreme = nullptr;

};
#endif //HEAP_H
