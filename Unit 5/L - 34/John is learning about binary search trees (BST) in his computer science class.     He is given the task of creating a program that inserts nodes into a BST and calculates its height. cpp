








#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data) {
    TreeNode* newNode = new TreeNode;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    TreeNode* root = nullptr;
    int numNodes, nodeData;

    std::cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        std::cin >> nodeData;
        root = insert(root, nodeData);
    }

    int treeHeight = height(root);

    std::cout <<  treeHeight ;

    return 0;
}
