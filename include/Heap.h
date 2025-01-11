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

    void insert(int value);

    void insertNode(Node* node);

    void clear();

    void remove();

    void mergeHeap(Heap* heap2);

    Heap() {
        this->roots.push_back(nullptr);
    }

    ~Heap() {
        this->roots.clear();
        this->extreme = nullptr;
    }

    Heap(Node* root);

    void printHeap();

private:
    Node* extreme = nullptr;
    std::vector<Node*> roots;
};
#endif //HEAP_H
