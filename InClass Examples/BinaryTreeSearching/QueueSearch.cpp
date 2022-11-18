#include <iostream>
#include "QueueSearch.h"

// Utility function to create a new tree node
Node* newNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root) {
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<Node*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false) {
		// Print front of queue and remove it from queue
		Node* node = q.front();
		cout << node->data << " ";
		q.pop();

		// Enqueue left child 
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}
}
