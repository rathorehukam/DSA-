











#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return create(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int sumGtr(Node* root, int value) {
    if (root == nullptr) {
        return 0;
    }

    if (root->data > value) {
        return root->data + sumGtr(root->left, value) + sumGtr(root->right, value);
    } else {
        return sumGtr(root->right, value);
    }
}

int main() {
    Node* root = nullptr;
    int n, data, target;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    cin >> target;

    int sum = sumGtr(root, target);
    cout << sum;

    return 0;
}
