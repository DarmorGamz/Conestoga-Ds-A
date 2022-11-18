/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

// Includes
#include <iostream>
#include "binaryTree.h"
using namespace std;

// Methods
int main() {
	binaryTree* MyTree = new binaryTree();

	MyTree->insert(100);
	MyTree->insert(25);
	MyTree->insert(11);
	MyTree->insert(2);
	MyTree->insert(87);
	MyTree->insert(50);
	MyTree->insert(35);

	node* tmp = MyTree->search(11);
	cout << "Found " << tmp->value << " located at " << (int)tmp << endl;

	MyTree->Display_preorder();
	cout << endl;
	MyTree->Display_inorder();
	cout << endl;
	MyTree->Display_postorder();

	delete MyTree;

	return 1;
}