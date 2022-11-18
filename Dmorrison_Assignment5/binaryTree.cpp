/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

// Includes.
#include "binaryTree.h"

/**
* Constructor.
*/
binaryTree::binaryTree() {
    Root = nullptr;
}

/**
* Destructor.
*/
binaryTree::~binaryTree() {

}

/**
* Inserts a value into a Binary Tree.
* @param int val Value to insert into a binary tree.
* @return void No expected return.
*/
void binaryTree::insert(int val) {
    /* If the tree is empty, return a new node */
    if (this->Root == nullptr) {
        this->Root = new node;
        this->Root->value = val;
        this->Root->left = nullptr;
        this->Root->right = nullptr;
        return;
    }

    // Create tmpNode to hold Root/Head location.
    node* tmpRoot = this->Root;

    // Key is smaller than root's key, go left, otherwise go right.
    if (val < this->Root->value) {
        this->Root = this->Root->left;
        this->insert(val);
        tmpRoot->left = this->Root;
    } else {
        this->Root = this->Root->right;
        this->insert(val);
        tmpRoot->right = this->Root;
    }

    // Reset Root to head.
    this->Root = tmpRoot;
}

/**
* Searches a Binary Tree for a value and returns it's pointer location.
* @param int val Value to search a binary tree for.
* @return node* returns a pointer to the node of a value.
*/
node* binaryTree::search(int val) {
    // Base Cases: root is null or key is present at root
    if (this->Root == nullptr || this->Root->value == val)
        return this->Root;

    // Create tmpNode to hold Root/Head location. NodeToReturn to store node to return.
    node* tmpRoot = this->Root;
    node* nodeToReturn = this->Root;

    // Key is greater than root's key go right, otherwise go left.
    if (this->Root->value < val) {
        this->Root = this->Root->right;
        nodeToReturn = search(val);
    } else {
        this->Root = this->Root->left;
        nodeToReturn = search(val);
    }

    // Reset Root to head.
    this->Root = tmpRoot;

    // Set Response.
    return nodeToReturn;
}


/**
* Prints a Binary Tree in pre_order.
* @return void No return expected.
*/
void binaryTree::Display_preorder() {
    // Base Cases: root is null or key is present at root
    if (this->Root == NULL) return;

    /* then print the data of node */
    std::cout << this->Root->value << ",";

    // Create tmpNode to hold Root/Head location.
    node* tmpRoot = this->Root;

    /* first recur on left child */
    this->Root = tmpRoot->left;
    Display_preorder();

    /* now recur on right child */
    this->Root = tmpRoot->right;
    Display_preorder();

    // Reset Root to head.
    this->Root = tmpRoot;
}

/**
* Prints a Binary Tree in in_order.
* @return void No return expected.
*/
void binaryTree::Display_inorder() {
    // Base Cases: root is null or key is present at root
    if(this->Root == nullptr) return;

    // Create tmpNode to hold Root/Head location.
    node* tmpRoot = this->Root;

    // first recur on left child 
    this->Root = this->Root->left;
    this->Display_inorder();
    this->Root = tmpRoot;

    // then print the data of node 
    std::cout << this->Root->value << ",";

    // now recur on right child 
    this->Root = this->Root->right;
    this->Display_inorder();
    this->Root = tmpRoot;
}

/**
* Prints a Binary Tree in post_order.
* @return void No return expected.
*/
void binaryTree::Display_postorder() {
    // Base Cases: root is null or key is present at root
    if (this->Root == nullptr) return;

    // Create tmpNode to hold Root/Head location.
    node* tmpRoot = this->Root;

    /* first recur on left child */
    this->Root = this->Root->left;
    Display_postorder();
    if (this->Root == nullptr) { this->Root = tmpRoot; }

    /* now recur on right child */
    this->Root = this->Root->right;
    Display_postorder();
    if (this->Root == nullptr) { this->Root = tmpRoot; }
    
    // Reset Root to head.
    this->Root = tmpRoot;

    /* then print the data of node */
    std::cout << this->Root->value << ",";
}
