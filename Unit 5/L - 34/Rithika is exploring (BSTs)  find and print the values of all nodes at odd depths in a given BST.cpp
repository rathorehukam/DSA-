




#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void printOddDepthPreorder(Node* root, int depth) {
    if (root == nullptr) {
        return;
    }

    if (depth % 2 == 1) {
        cout << root->data << " ";
    }

    printOddDepthPreorder(root->left, depth + 1);
    printOddDepthPreorder(root->right, depth + 1);
}

int main() {
    Node* root = nullptr;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Values at odd depths: ";
    printOddDepthPreorder(root, 1);

    return 0;
}
