/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef PRODUCTREGISTRATION_H_
#define PRODUCTREGISTRATION_H_

/** INCLUDES ******************************************************************/


/** CLASSES, STRUCTURES AND ENUMERATIONS *************************************/
struct node {
	int key_value;
	node* left;
	node* right;
};

class RegistrationTree {
public:
    RegistrationTree();
    ~RegistrationTree();

    bool RegisterProduct(unsigned key);
    bool IsRegistered(unsigned key);
    node* search(int key);
    void destroy_tree();

    void print();
    node* root;
private:
    void destroy_tree(node* leaf);
    void insert(int key, node* leaf);
    node* search(int key, node* leaf);

};
#endif /* PRODUCTREGISTRATION_H_ */