










#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    if (root->val % 2 == 0) {
        cout << root->val << " ";
    }
    inOrder(root->right);
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    inOrder(root);

    cout << endl;

    return 0;
}
