#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::~TreeNode() {}

void TreeNode::insert(int value) {
    if (value < data) {
        if (left == nullptr) {
            left = new TreeNode();
            left->data = value;
        } else {
            left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = new TreeNode();
            right->data = value;
        } else {
            right->insert(value);
        }
    }
}

void TreeNode::preorder() {
    std::cout << data << " ";
    if (left != nullptr) {
        left->preorder();
    }
    if (right != nullptr) {
        right->preorder();
    }
}
