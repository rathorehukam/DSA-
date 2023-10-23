#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == nullptr) {
        exit(1);
    }
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

int isBST(TreeNode* root, int min_val, int max_val) {
    if (root == nullptr) {
        return 1; 
    }

    if (root->value <= min_val || root->value >= max_val) {
        return 0; 
    }

    return isBST(root->left, min_val, root->value) && isBST(root->right, root->value, max_val);
}

int main() {
    TreeNode* root = nullptr;

    int num_nodes;
    cin >> num_nodes;

    for (int i = 0; i < num_nodes; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree";
    }
    else {
        cout << "The tree is not a Binary Search Tree";
    }

    free(root);

    return 0;
}
