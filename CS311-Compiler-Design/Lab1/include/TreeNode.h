#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
public:
    TreeNode();
    ~TreeNode();
    int data;
    TreeNode *left;
    TreeNode *right;
    void insert(int value);
    void preorder();
};

#endif // TREE_NODE_H
