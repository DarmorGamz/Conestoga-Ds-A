/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef TASK_H_
#define TASK_H_

/** INCLUDES ******************************************************************/
#include "Product.h"
#include <queue>
#include <stack>

/** CLASSES, STRUCTURES AND ENUMERATIONS *************************************/
class Task {
private:
	std::string Name;
	std::queue<Product*> ProdQ;
	std::stack<Item*> Inventory;

public:
	Task(std::string);
	void Run();
	Product* MoveProduct();
	void AddProduct(Product*);
};


#endif /* TASK_H_ */