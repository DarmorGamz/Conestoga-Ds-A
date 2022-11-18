// C++ program to demonstrate 
// delete operation in binary search tree
#include <iostream>
using namespace std;
//Node class
class Node {
public:
	int key;
	Node* left, * right;
	Node(int item);
};
// Constructor
Node::Node(int item) {
	key = item;
	left = right = NULL;
}

/* A utility function to   
insert a new node with given key in
* BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return new Node(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
Node* minValueNode(Node* node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Given a binary tree, print its nodes in preorder
void printPreorder(Node* node)
{
	if (node == NULL)
		return;

	/* then print the data of node */
	cout << node->key << " ";

	/* first recur on left child */
	printPreorder(node->left);

	/* now recur on right child */
	printPreorder(node->right);
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
Node* deleteNode(Node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// node with two children: Get the inorder successor
			 // (smallest in the right subtree)
		Node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	} // of else
	return root;
}

// Given a binary tree, print its nodes in inorder
void inorder(Node* node)
{
	if (node == NULL)
		return;

	// first recur on left child 
	inorder(node->left);

	// then print the data of node 
	cout << node->key << " ";

	// now recur on right child 
	inorder(node->right);
}


int main()
{
	/* Let us create following BST
	                    50
	                /        \
	                25       70
	                / \ 		/ \
	        		10 35 		60 80 */
	Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 25);
	root = insert(root, 70);
	root = insert(root, 10);
	root = insert(root, 35);
	root = insert(root, 60);
	root = insert(root, 80);
	root = insert(root, 55);
	root = insert(root, 65);
	root = insert(root, 75);
	root = insert(root, 90);
	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 10\n";
	root = deleteNode(root, 10);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 25\n";
	root = deleteNode(root, 25);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 70\n";
	root = deleteNode(root, 70);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);
	return 0;
}


