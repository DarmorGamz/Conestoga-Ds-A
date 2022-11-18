#include <iostream>
#include "BinarySearch.h"

using namespace std;

Node* newNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void printLevelOrder(Node* root) {
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

void printCurrentLevel(Node* root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int height(Node* node) {
	if (node == NULL)
		return 0;
	else {
		// compute the height of each subtree 
		int lheight = height(node->left);
		int rheight = height(node->right);

		// use the larger one 
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}
