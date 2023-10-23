




#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return (Node*)malloc(sizeof(Node)); 
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* deleteEvenNodes(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    root->left = deleteEvenNodes(root->left);
    root->right = deleteEvenNodes(root->right);
    if (root->data % 2 == 0) {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root); 
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root); 
            return temp;
        }
        Node* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        root->data = successor->data;
        root->right = deleteEvenNodes(root->right);
    }
    return root;
}

void printBST(Node* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    root = deleteEvenNodes(root);
    printBST(root);
    return 0;
}
