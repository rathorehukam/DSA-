










#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* findMinNode(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root; // Return nullptr if the tree is empty
    }

    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMinNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->value = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (key < root->value) {
        root->left = insert(root->left, key);
    } else if (key > root->value) {
        root->right = insert(root->right, key);
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;
    int n, val, key;

    
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> val;
        root = insert(root, val);
    }

    inorderTraversal(root);
    std::cout << std::endl;

    std::cin >> key;

    TreeNode* result = deleteNode(root, key);

    if (result == nullptr) {
        std::cout << "The node to be deleted is not present." << std::endl;
    } else {
        inorderTraversal(result);
        std::cout << std::endl;
    }


    return 0;
}
