#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void printOddDepthValues(Node* root, int depth) {
    if (root == nullptr) {
        return;
    }
    if (depth % 2 != 0) {
        std::cout << root->data << " ";
    }
    printOddDepthValues(root->left, depth + 1);
    printOddDepthValues(root->right, depth + 1);
}

int main() {
    Node* root = nullptr;
    int n, data;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> data;
        root = insert(root, data);
    }

    printOddDepthValues(root, 1);
    std::cout << std::endl;

    return 0;
}
