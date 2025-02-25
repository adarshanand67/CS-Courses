#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {
    TreeNode *root = new TreeNode();
    root->data = 5;
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);

    std::cout << "Pre-order traversal: ";
    root->preorder();
    std::cout << std::endl;

    return 0;
}
