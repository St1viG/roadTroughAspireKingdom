//
// Created by Stevan on 2025-01-10.
//
#include "Heap.h"
#include <stack>
Node *Node::mergeTrees(Node *root1, Node *root2) {
    if (root1->value < root2->value)
        std::swap(root1, root2);
    root1->children.push_back(root2);
    root1->level++;
    return root1;
}
void Heap::insert(int value) {
    Node *newNode = new Node(value);
    Heap *newHeap = new Heap(newNode);
    this->mergeHeap(newHeap);
}

Heap::Heap(Node *root) {
    if (root!=nullptr)
        roots.push_back(root);
}

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
                    if (roots[temp->level] == nullptr) {
                        roots[temp->level] = temp;
                        break;
                    }
                    if (temp->level >= roots.size()) {
                        roots.push_back(temp);
                        break;
                    }
                }
            }
        }
    }
}


void Heap::printHeap() {
    for (auto const x: roots) {
        Node::printTree(x);
    }
}

//void Node::printTree(Node* root) {
//    if (root == nullptr) return;
//    std::cout << root->value << " ";
//    for (auto & i : root->children) {
//        printTree(i);
//    }
//}

void Node::printTree(Node* root)
{
    std::stack<std::pair<Node*,int>> stek;
    if(root!= nullptr)
        stek.push({root,0});
    while (!stek.empty()) {
        Node* x=stek.top().first;
        int tab = stek.top().second;
        stek.pop();
        for(int i=0;i<tab;i++)
            std::cout<<"\t";
        std::cout<<x->value<<std::endl;
        for (int i = x->children.size()-1; i >= 0; i--) {
            if (x->children[i] != nullptr)
                stek.push({x->children[i],tab + 1});
        }
    }
}