#include <iostream>
#include <iomanip>

using namespace std;
class Record {
    public:
        string firstName;
        string lastName;
        int Number;
        int Mark;
        Record(string, string, int, int);

};

Record::Record(string First, string Last, int num, int mark) {
    firstName = First;
    lastName = Last;
    Number = num;
    Mark = mark;
}

class Node {
public:
    Record* key;
    Node* left, * right;
    Node(Record* item);
};
// Constructor
Node::Node(Record* item) {
    key = item;
    left = right = NULL;
}

Node* insert(Node* node, Record* key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return new Node(key);

    /* Otherwise, recur down the tree */
    if (key->firstName < node->key->firstName)
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
    cout << node->key->firstName << " ";

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
	if (key->firstName < root->key->firstName)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key->firstName > root->key->firstName)
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

int main()
{
	
	Record* Darren = new Record("Darren", "Morrison", 1, 100);
	Node* root = NULL;
	root = insert(root, Darren);
	printPreorder(root);

	return 0;
}