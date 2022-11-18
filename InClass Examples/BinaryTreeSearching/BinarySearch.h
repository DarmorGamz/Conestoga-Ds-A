// Includes.
#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left, * right;
};

// Prototypes.
void printCurrentLevel(Node* root, int level);
void printLevelOrder(Node* root);
int height(Node* node);
Node* newNode(int data);