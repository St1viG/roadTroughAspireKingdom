//
// Created by Me on 2025-01-11.
//
#include "../include/Node.h"

//Merges 2 trees to keep Binome tree property
Node *Node::mergeTrees(Node *root1, Node *root2) {
    if (root1->value < root2->value)
        std::swap(root1, root2);
    root1->children.push_back(root2);
    root1->level++;
    return root1;
}

void Node::printTree(Node* root)
{
    std::stack<std::pair<Node*,int>> stek;
    if(root!= nullptr)
        stek.push({root,0});
    while (!stek.empty()) {
        Node* x=stek.top().first;
        int tab = stek.top().second;
        stek.pop();
        for(int i=0;i<2*tab;i++)
            std::cout<<"\t";
        std::cout<<x->value<<std::endl;
        for (int i = x->children.size()-1; i >= 0; i--) {
            if (x->children[i] != nullptr)
                stek.push({x->children[i],tab + 1});
        }
    }
}