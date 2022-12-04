/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "ProductRegistration.h"
#include <cstddef>
#include <string>
#include <iostream>

/**
* Constructor
*/
RegistrationTree::RegistrationTree() {
	root = NULL;
}

/**
* Deconstructor
*/
RegistrationTree::~RegistrationTree() {
	destroy_tree();
}

/**
* Registeres a S/N
* @param int key Key to search for.
* @return bool Returns if insert was successful.
*/
bool RegistrationTree::RegisterProduct(unsigned key) {
    // Verify S/N doesn't already exist.
    if (search(key) != nullptr) return false;

    // Insert S/N
    if (root != NULL)
        insert(key, root);
    else {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
    return true;
}

/**
* Search for a key value.
* @param unsigned key Key to search for.
* @return bool Returns if S/N is found.
*/
bool RegistrationTree::IsRegistered(unsigned key) {
    // S/N is registered.
    if (search(key) != nullptr) return true;

    // S/N is not registered.
    return false;
}

/**
* Search for a key value.
* @param int key Key to search for.
* @return node* Returns a Node pointer if found.
*/
node* RegistrationTree::search(int key) {
    return search(key, root);
}

/**
* Destroy the tree
* @return void No return value.
*/
void RegistrationTree::destroy_tree() {
    destroy_tree(root);
}

/**
* Destroy the tree
* @param node* leaf Current node being searched
* @return void No return value.
*/
void RegistrationTree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

/**
* Insert a key value.
* @param int key Key to search for.
* @param node* leaf Current node being searched
* @return void No return value.
*/
void RegistrationTree::insert(int key, node* leaf) {
    if (key < leaf->key_value) {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;   
            leaf->left->right = NULL;   
        }
    }
    else if (key >= leaf->key_value) {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;  
            leaf->right->right = NULL; 
        }
    }
}

/**
* Search for a given key.
* @param int key Key to search for.
* @param node* leaf Current node being searched
* @return Node* Return Pointer to node if found, otherwise return nullptr
*/
node* RegistrationTree::search(int key, node* leaf) {
    if (leaf != NULL) {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}


/**
* Used to print the BinaryTree (In Order)
* @return void No return value.
*/
void RegistrationTree::print() {
    // Base Cases: root is null or key is present at root
    if (this->root == nullptr) return;

    // Create tmpNode to hold Root/Head location.
    node* tmpRoot = this->root;

    // first recur on left child 
    this->root = this->root->left;
    this->print();
    this->root = tmpRoot;

    // then print the data of node 
    std::cout << this->root->key_value << ",";

    // now recur on right child 
    this->root = this->root->right;
    this->print();
    this->root = tmpRoot;
}