/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

// Includes
#include <iostream>

// Structures
struct node {
	int value;
	node* left;
	node* right;
};

// Classes
class binaryTree {
public:
	node* Root;

	binaryTree();
	~binaryTree();

	void insert(int);
	node* search(int);
	void Display_inorder();
	void Display_postorder();
	void Display_preorder();
};