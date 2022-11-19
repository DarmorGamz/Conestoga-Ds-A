/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef PRODUCT_H_
#define PRODUCT_H_

/** INCLUDES ******************************************************************/
#include <string>


/** TYPEDEFS, STRUCTURES AND ENUMERATIONS *************************************/
enum Status {
	NotReady,
	Ready,
	BackOrdered,
};

struct Item {
	std::string Name;
	unsigned int SN;
};

struct Product {
	unsigned int SN;
	Item Components[8];
	Status status;
};


#endif /* PRODUCT_H_ */