





#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int item) {
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

int findDepth(Node* root, int x) {
	if (root == NULL)
		return -1;

	int dist = -1;

	if ((root->data == x) || (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0)
		return dist + 1;

	return dist;
}

int main() {
	Node* root = newNode(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		if (i == 0) {
			root->data = value;
		} else {
			Node* current = root;
			while (true) {
				if (value < current->data) {
					if (current->left == nullptr) {
						current->left = newNode(value);
						break;
					}
					current = current->left;
				} else if (value > current->data) {
					if (current->right == nullptr) {
						current->right = newNode(value);
						break;
					}
					current = current->right;
				} else {
					break;
				}
			}
		}
	}

	int k;
	cin >> k;
	cout << findDepth(root, k) << "\n";
	return 0;
}
