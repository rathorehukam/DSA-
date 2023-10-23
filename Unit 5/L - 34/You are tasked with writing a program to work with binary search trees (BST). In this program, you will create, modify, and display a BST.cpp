










#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}


Node* findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

Node* deleteMax(Node* root) {
    if (root == nullptr)
        return root;

    if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    root->right = deleteMax(root->right);
    return root;
}


void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

   
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        root = insert(root, value);
    }

    Node* maxNode = findMax(root);
    std::cout << "Node with the maximum value to be deleted: " << maxNode->data << std::endl;
    root = deleteMax(root);

    std::cout << "BST after deleting the maximum value node: ";
    inOrderTraversal(root);
  

    return 0;
}
