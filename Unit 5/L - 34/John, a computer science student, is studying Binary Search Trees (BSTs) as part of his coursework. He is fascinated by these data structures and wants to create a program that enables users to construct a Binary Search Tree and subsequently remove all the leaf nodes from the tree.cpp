



#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

TreeNode* deleteLeafNodes(TreeNode* root) {
    if (root == nullptr) return nullptr;
    
    if (root->left == nullptr && root->right == nullptr) {
        free(root);
        return nullptr;
    }
    
    root->left = deleteLeafNodes(root->left);
    root->right = deleteLeafNodes(root->right);
    
    return root;
}

void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;
    
    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    root = deleteLeafNodes(root);
    
    if (root == nullptr) {
        cout << "Empty tree";
    } else {
        printInOrder(root);
        cout << endl;
    }

    return 0;
}
