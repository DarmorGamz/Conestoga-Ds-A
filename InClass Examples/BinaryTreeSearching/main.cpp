// Includes.
#include <iostream>
#include "BinarySearch.h"

int main() {
	Node* root = newNode(50);
	root->left = newNode(17);
	root->right = newNode(76);
	root->left->left = newNode(9);
	root->left->right = newNode(23);
	root->right->left = newNode(54);
	root->left->left->right = newNode(14);
	root->left->right->left = newNode(19);
	root->right->left->right = newNode(72);
	root->left->left->right->right = newNode(12);
	root->right->left->right->left = newNode(67);
	root->right->left->right->left = newNode(80);
	root->right->left->right->left = newNode(67);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);

	return 0;

}