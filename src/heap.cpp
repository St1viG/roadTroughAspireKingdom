//
// Created by Me on 2025-01-10.
//
#include "../include/Heap.h"

//Inserts a new value into heap by creating new heap with desired node and merging it together into first
void Heap::insert(int value) {
    Node *newNode = new Node(value);
    Heap *newHeap = new Heap(newNode);
    this->mergeHeap(newHeap);
    numberOfNodes += 1;
}

//Inserts a node into heap (same method as first one but argument is a node instead of integer)
void Heap::insertNode(Node* node) {
    Heap *newHeap = new Heap(node);
    this->mergeHeap(newHeap);
    numberOfNodes += 1;
}

//Clears roots of the heap
void Heap::clear(){
    roots.clear();
}

Heap::Heap(Node *root) {
    if (root!=nullptr)
        roots.push_back(root);
}

//Merges 2 heaps by adding roots of second one into first and merging it to keep binomal heap order
void Heap::mergeHeap(Heap *heap2) {
    for (auto const& child : heap2->roots) {
        if (child == nullptr)
            continue;
        if (child->level >= roots.size()) {
            for (int i = roots.size(); i < child->level; ++i)
                roots.push_back(nullptr);
            roots.push_back(child);
        } else {
            if (roots[child->level] == nullptr) {
                roots[child->level] = child;
            } else {
                Node *temp = child;
                while (true) {
                    temp = Node::mergeTrees(temp, roots[temp->level]);
                    roots[temp->level - 1] = nullptr;
                    if (temp->level >= roots.size()) {
                        roots.push_back(temp);
                        break;
                    }
                    if (roots[temp->level] == nullptr) {
                        roots[temp->level] = temp;
                        break;
                    }
                }
            }
        }
    }
    delete heap2;
}

void Heap::printHeap() {
    for (auto const x: roots) {
        Node::printTree(x);
    }
}

//Removes the top (biggest or smallest number in heap)
void Heap::remove() {
    if (roots.empty()||roots.back()==nullptr) {
        std::cout<<"Empty bag!"<<std::endl;
        return;
    }
    Node* extr = nullptr;
    int pos;
    for (int i=0;i<roots.size();i++) {
        if (roots[i] != nullptr) {
            extr = roots[i];
            pos = i;
            break;
        }
    }
    for (int i=pos + 1;i<roots.size();i++) {
        if (roots[i] == nullptr)
            continue;
        if (extr && extr->value < roots[i]->value) {
            extr = roots[i];
            pos = i;
        }
    }
    if (!extr)
        return;
    Heap *newHeap = new Heap();
    for (auto x: extr->children) {
        if (x != nullptr) {
            newHeap->insertNode(x);
        }
    }
    roots.erase(roots.begin()+pos);
    this->Heap::mergeHeap(newHeap);
}