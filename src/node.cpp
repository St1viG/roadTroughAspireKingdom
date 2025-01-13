//
// Created by Me on 2025-01-11.
//
#include "../include/Node.h"

//Merges 2 trees to keep Binomial tree property
Node *Node::mergeTrees(Node *root1, Node *root2, bool isMax) {
    if ((isMax && root1->value < root2->value) || (!isMax && root1->value > root2->value))
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

//Function that switches the three in binomial heap from max -> min and other way around and fixes tree to keep binomal tree property
void Node::switchTree(bool isMax) {
    if (this->children.empty())
        return;
    std::stack<Node*> stek;
    stek.push(this);
    if (isMax) {
        while (!stek.empty()) {
            Node* temp = stek.top();
            stek.pop();
            Node* temp2 = nullptr;
            int extreme = INT_MAX;
            for (auto x: temp->children) {
                x->parent = temp;
                if (x->value < extreme) {
                    extreme = x->value;
                    temp2 = x;
                }
                stek.push(x);
            }
            if (temp2) {
                while (temp2->value < temp->value) {
                    std::swap(temp2->value, temp->value);
                    temp2 = temp;
                    temp = temp->parent;
                    if (temp == nullptr)
                        break;
                }
            }
        }
    }
    else {
        while (!stek.empty()) {
            Node* temp = stek.top(), *swap;
            stek.pop();
            Node* temp2 = nullptr;
            int extreme = INT_MIN;
            for (auto x: temp->children) {
                x->parent = temp;
                if (x->value > extreme) {
                    extreme = x->value;
                    temp2 = x;
                }
                stek.push(x);
            }
            if (temp2) {
                while (temp2->value > temp->value) {
                    std::swap(temp2->value, temp->value);
                    temp2 = temp;
                    temp = temp->parent;
                    if (temp == nullptr)
                        break;
                }
            }
        }
    }
}