/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "Task.h"

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
Task::Task(std::string name) { // TODO Does there need to be an inital quantity to the inventory.
	this->Name = name;
}

/**
* Using FIFO determine if the next item in the queue needs this Task's component. Do something about it, and set it's status.
* @return void No return value.
*/
void Task::Run() {
	if(!this->ProdQ.empty()) {
		// Gets next ready item in queue.
		Product* tempProduct = this->ProdQ.front();
		int index = -1;
		for(int i = 0; i < (sizeof(tempProduct->Components)/sizeof(Item)); i++) { // TODO break this loop if item is found to be faster.
			if(tempProduct->Components[i].Name == this->Name) {
				index = i;
			}
		}

		if(index != -1) { // Product needs this Component
			if(!this->Inventory.empty()) { // If this inventory isn't empty.
				tempProduct->status = Status::Ready;
			} else {
				tempProduct->status = Status::BackOrdered;
			}
		}
	}
}

/**
* Using FIFO determine if the next item in the queue is ready to move. Pop it from the queue.
* @return void No return value.
*/
Product* Task::MoveProduct() {
	if(!this->ProdQ.empty()) {
		Product* tempProduct = this->ProdQ.front();
		if(tempProduct->status == Status::Ready || tempProduct->status == Status::BackOrdered) {
			this->ProdQ.pop();
			return tempProduct;
		}
		return nullptr; // Item is not Ready.
	} else {
		return nullptr; // No items in queue.
	}
}

/**
* Using FIFO add a product to the end of the queue.
* @param Product* pProduct pointer to Product structure instance.
* @return void No return value.
*/
void Task::AddProduct(Product* pProduct) {
	this->ProdQ.push(pProduct);
}