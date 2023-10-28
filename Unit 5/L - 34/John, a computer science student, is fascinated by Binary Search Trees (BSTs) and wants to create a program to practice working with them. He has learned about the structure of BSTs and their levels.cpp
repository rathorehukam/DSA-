







#include <iostream>
#include <vector>

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

TreeNode* deleteEvenNodes(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    root->left = deleteEvenNodes(root->left);
    root->right = deleteEvenNodes(root->right);
    if (root->val % 2 == 0) {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        } else {
            TreeNode* minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            root->val = minNode->val;
root->right = deleteEvenNodes(root->right);
        }
    }
    return root;
}

void inOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
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

    root = deleteEvenNodes(root);

    vector<int> result;
    inOrder(root, result);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
